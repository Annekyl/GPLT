#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

/*
  题目解析与解法概要（中文注释版）：
  有 2^k 个选手，完全淘汰赛以满二叉树形式组织（用堆式编号：根=1，左右子为
  2*i,2*i+1）。 给定每个内部节点（每场比赛）的败者能力
  l_{i,j}（映射到内部节点），以及根的最终胜者能力 w。 要求恢复叶子（选手）的能力
  a_1..a_{2^k}，使得模拟比赛得到的每场败者恰好与输入 l 匹配，根胜者为 w。

  关键思想：
  - 对每个节点 u（包含内部节点和叶子），维护
  mmin[u]：该子树在根节点处（该子树胜者）能取得的最小可能能力值（若该子树无法构造则为
  INF）。
  - 叶子节点 mmin = 1（理论上能力下界为 1，题目能力 >=1）。
  - 对内部节点 u，设左/右子 mmin 分别为 ml,mr，且该场比赛败者值为 l(u)。
    我们想找该场比赛的最小可能胜者 W（即 mmin[u]）满足存在左右子树胜者值
  L,R，使得：
      - 若 L!=R，则胜者为 max(L,R)，败者为 min(L,R);
      - 若 L==R，则胜者为 L(=R)，败者为 L(=R).
    推导得到可能的情况：
      1) 如果 ml <= l && mr <= l ：可以令 L=R=l，则 W = l 可行；
      2) 若左子能降低到 <= l（ml <= l），右子需承受 W，此时要保证右子能接受
  W，因此 W >= max(l+1, mr)（W 必须 > l 才能让败者恰为 l，且右子至少要能输出
  mr）； 3) 对称地，如果 mr <= l，则 W >= max(l+1, ml) 也可行。 于是 mmin[u] =
  上述可能值中的最小值（若都不可行则为 INF）。
  - 先自底向上计算所有 mmin。
  - 若根的 mmin > 给定的 w，则无解（"No Solution"）。
  - 否则自顶向下，根据给定的根胜者
  w，确定每个内部节点的左右子在该场比赛中应供给的胜者值（ winreq[u] 表示节点 u
  在该子树中需要产出的胜者值）：
      - 若 winreq[u] == l(u)，则左右都必须给 l(u)；
      - 若 winreq[u] > l(u)，则必须让一边给 l(u)（作为败者），另一边给
  winreq[u]（作为胜者），选择能够满足 mmin 限制的一边。
  - 得到叶子 winreq
  值即为选手能力。最后用一次完整模拟验证（每个内部节点计算两个子胜者产生的败者是否恰为输入的
  l），若不匹配则无解。
  - 复杂度：O(2^k)，k ≤ 18 可接受。

  注意：
  - 堆式编号：叶节点编号范围为 [N, 2*N-1]，内部节点为 [1, N-1]，其中 N = 2^k。
  - lnode[u] 当 u 为内部节点时保存对应的败者值。
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    if (!(cin >> k))
        return 0;
    int N = 1 << k; // 叶子数（选手数）
    // 节点编号 1 .. 2*N-1，内部 1..N-1，叶 N..2N-1
    vector<ll> lnode(2 * N, 0); // 存放每个内部节点的败者值 l，其他位置无意义

    // 输入按题目按轮给出的 l_{i,j}，需要映射到堆式编号中
    // 我们可以把第 i 轮（i 从 1 到 k）对应的内部节点在完全二叉树的某一层
    // 计算映射：对于轮 i，节点所在深度为 depth = i (根为 i=1 对应
    // depth=1)，但是输入格式的 j 数量为 2^{k-i} 更方便地，考虑按 heap 层：根层
    // depth=1 对应 1 个内部节点；第 depth 层（内部节点）编号从 2^{depth-1} ..
    // 2^{depth}-1 输入第 i 行给的是 depth = i 对应的 2^{k-i}
    // 个值，但原题给的是按 i 从 1 到 k，k 行。映射方法如下： 实际上第 i
    // 行对应深度 = i （从 1 根到 k 最底的内部层），但我们要把它放到编号 base =
    // 2^{i-1} + (j-1) 下面按给定方式映射（与之前推导一致）
    for (int i = 1; i <= k; ++i) {
        int cnt = 1 << (k - i);      // 该行输入的个数
        int depth = k - i + 1;       // 这些数对应内部节点的层级（堆编号层）
        int base = 1 << (depth - 1); // 层第一个节点编号
        for (int j = 1; j <= cnt; ++j) {
            ll val;
            cin >> val;
            int idx = base + (j - 1);
            if (idx >= 1 && idx <= N - 1)
                lnode[idx] = val;
        }
    }

    ll w;
    cin >> w; // 根最终胜者

    // mmin 数组：记录每个节点在其子树能输出的最小可能胜者值
    vector<ll> mmin(2 * N, INF);
    // 叶子可以是任意 >=1，因此设最小为 1（题目中 ai >= 1）
    for (int i = N; i <= 2 * N - 1; ++i)
        mmin[i] = 1;

    // 自底向上计算内部节点的 mmin
    for (int idx = N - 1; idx >= 1; --idx) {
        ll l = lnode[idx];          // 该场败者值
        ll ml = mmin[idx << 1];     // 左子最小胜者
        ll mr = mmin[idx << 1 | 1]; // 右子最小胜者

        ll best = INF;

        // 情况1：两子都可以取到 <= l，则可以让两子都 = l，使得败者 = l，胜者 =
        // l
        if (ml <= l && mr <= l) {
            best = min(best, l);
        }
        // 情况2：左子取 l（需 ml <= l），右子承担胜者 W，W 必须 >= max(l+1, mr)
        if (ml <= l && mr != INF) {
            ll cand = max(l + 1, mr);
            best = min(best, cand);
        }
        // 情况3：右子取 l（需 mr <= l），左子承担胜者 W，W 必须 >= max(l+1, ml)
        if (mr <= l && ml != INF) {
            ll cand = max(l + 1, ml);
            best = min(best, cand);
        }
        // 若上述都不可行，best 保持 INF 表示该子树无法满足给定的败者要求
        mmin[idx] = best;
    }

    // 根必须至少能达到给定的 w，否则无解
    if (mmin[1] == INF || w < mmin[1]) {
        cout << "No Solution\n";
        return 0;
    }

    // 自顶向下确定每个节点在该解中的胜者值 winreq（根给定为 w）
    vector<ll> winreq(2 * N, 0);
    winreq[1] = w;

    // 用栈/队列做 DFS/BFS 下推
    vector<int> stk;
    stk.push_back(1);
    bool ok = true;
    while (!stk.empty() && ok) {
        int u = stk.back();
        stk.pop_back();
        if (u >= N)
            continue; // 叶子无需展开
        ll W = winreq[u];
        ll l = lnode[u];
        if (W < l) {
            // 胜者值小于败者值不可能
            ok = false;
            break;
        }
        int L = u << 1, R = u << 1 | 1;
        ll ml = mmin[L], mr = mmin[R];

        if (W == l) {
            // 必须让左右都为 l
            // 但是左右子必须能够产生胜者 = l（即 mmin[child] <= l）
            if (ml <= l && mr <= l) {
                winreq[L] = l;
                winreq[R] = l;
                stk.push_back(L);
                stk.push_back(R);
            } else {
                ok = false;
                break;
            }
        } else {
            // W > l，那么一边输出 l，另一边输出
            // W。选择哪边取决于哪个子树能够产出 l 以及另一边能接受 W。
            bool leftCanL = (ml <= l);
            bool rightCanL = (mr <= l);
            bool leftCanW =
                (ml <= W); // 一般来说 ml <= W 必须成立（子树能产出不超过 W
                           // 的胜者），但我们更关注 mmin <= required
            bool rightCanW = (mr <= W);

            // 首先尝试把左子设置为 l，右子为 W（若合法）
            if (leftCanL && rightCanW) {
                winreq[L] = l;
                winreq[R] = W;
                stk.push_back(L);
                stk.push_back(R);
            }
            // 否则尝试把右子设置为 l，左子为 W
            else if (rightCanL && leftCanW) {
                winreq[L] = W;
                winreq[R] = l;
                stk.push_back(L);
                stk.push_back(R);
            } else {
                // 两种分配都不行 -> 无解
                ok = false;
                break;
            }
        }
    }

    if (!ok) {
        cout << "No Solution\n";
        return 0;
    }

    // 叶子能力由叶子节点的 winreq 给出
    vector<ll> a(N + 1, 0); // a[1..N]
    for (int i = 0; i < N; ++i) {
        int idx = N + i;
        a[i + 1] = winreq[idx];
        if (a[i + 1] == 0)
            a[i + 1] = 1; // 严谨性保护（不应出现）
    }

    // 最后做一次仿真验证：自底向上计算每个内部节点的胜者与败者，验证败者是否等于输入
    // lnode，且根胜者等于 w
    vector<ll> winner(2 * N, 0);
    for (int i = N; i <= 2 * N - 1; ++i)
        winner[i] = a[i - N + 1];
    bool valid = true;
    for (int u = N - 1; u >= 1; --u) {
        ll L = winner[u << 1], R = winner[u << 1 | 1];
        ll wcalc = (L == R ? L : max(L, R)); // 胜者
        ll lcalc = (L == R ? L : min(L, R)); // 败者
        if (lcalc != lnode[u]) {
            valid = false;
            break;
        }
        winner[u] = wcalc;
    }
    if (!valid || winner[1] != w) {
        cout << "No Solution\n";
        return 0;
    }

    // 输出叶子能力 a1..aN
    for (int i = 1; i <= N; ++i) {
        if (i > 1)
            cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
