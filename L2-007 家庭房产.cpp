#include "bits/stdc++.h"

// #define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

// constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;
int fa[N];
int tcnt[N]; // 房产套数
int tsz[N];  // 房产总面积
int tnum[N]; // 人数
bool v[N];

struct node {
    int val, num;
    double acnt, asz;
};

void init() {
    for (int i = 0; i < 10000; i++) {
        fa[i] = i;
        tnum[i] = 1;
        tcnt[i] = 0;
        tsz[i] = 0;
    }
}

int get(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    // 大数合并到小数
    x = get(x);
    y = get(y);
    if (x < y)
        swap(x, y);

    // x为大数，y为小数
    tcnt[y] += tcnt[x];
    tsz[y] += tsz[x];
    tnum[y] += tnum[x];
    fa[x] = y;
}

void solve() {
    init();
    cin >> n;
    while (n--) {
        int id, fid, mid, k, cid[5], cnt, sz;
        cin >> id >> fid >> mid >> k;
        for (int i = 0; i < k; i++)
            cin >> cid[i];
        cin >> cnt >> sz;

        v[id] = 1;
        if (fid != -1)
            v[fid] = 1;
        if (mid != -1)
            v[mid] = 1;
        for (int i = 0; i < k; i++)
            if (cid[i] != -1)
                v[cid[i]] = 1;

        if (fid != -1 && get(id) != get(fid))
            merge(id, fid);
        if (mid != -1 && get(id) != get(mid))
            merge(id, mid);
        for (int i = 0; i < k; i++)
            if (cid[i] != -1 && get(id) != get(cid[i]))
                merge(id, cid[i]);
        id = get(id);
        tcnt[id] += cnt;
        tsz[id] += sz;
    }

    set<int> ans;
    for (int i = 0; i < 10000; i++) {
        if (!v[i])
            continue;
        ans.insert(get(i));
    }

    cout << ans.size() << endl;
    node out[ans.size()];
    int idx = 0;
    for (auto x : ans) {
        // cout << x << " " << tnum[x] << " " << tcnt[x] << " " << tsz[x] <<
        // endl; printf("%5d %d % %\n",);
        out[idx++] = {x, tnum[x], 1.0 * tcnt[x] / tnum[x],
                      1.0 * tsz[x] / tnum[x]};
    }

    sort(out, out + idx, [](node &a, node &b) {
        if (fabs(a.asz - b.asz) < 1e-6)
            return a.val < b.val;
        return a.asz > b.asz;
    });

    for (int i = 0; i < idx; i++) {
        printf("%04d %d %.3lf %.3lf\n", out[i].val, out[i].num, out[i].acnt,
               out[i].asz);
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}