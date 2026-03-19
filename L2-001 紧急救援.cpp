#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 5e5+10;

/*
注意N开大点，题目没有给出边的条数，或者在读取到m之后再创建数组
*/

int n, m, s, ed;
int a[N];
vi cnt(N, 0);    // 到达每个节点的路径条数
vi dist(N, INF); // 到达每个节点的最短路径
vi sum(N, 0);    // 到达每个节点的救援队总数
int pre[N];      // 每个节点的前驱节点
bool v[N];

int edge[N], ver[N], head[N], ne[N], tot;

void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    ne[tot] = head[x];
    head[x] = tot;
}

void solve() {
    memset(head, -1, sizeof head);
    memset(pre, -1, sizeof pre);
    cin >> n >> m >> s >> ed;
    FOR(i, 0, n - 1) cin >> a[i];
    FOR(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }

    dist[s] = 0;
    cnt[s] = 1;
    sum[s] = a[s];
    pre[s] = -1;

    priority_queue<pii> q;
    q.push({0, s});
    while (q.size()) {
        int d = -q.top().first, x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        // if (x == ed)
        //     break;
        v[x] = 1;
        for (int i = head[x]; i != -1; i = ne[i]) {
            int y = ver[i], z = edge[i];
            if (d + z < dist[y]) {
                dist[y] = d + z;
                cnt[y] = cnt[x];
                sum[y] = sum[x] + a[y];
                pre[y] = x;
                q.push(make_pair(-dist[y], y));
            } else if (d + z == dist[y]) {
                cnt[y] += cnt[x];
                if (sum[y] < sum[x] + a[y]) {
                    sum[y] = sum[x] + a[y];
                    pre[y] = x;
                }
            }
        }
    }
    cout << cnt[ed] << " " << sum[ed] << endl;
    vi path;
    int p = ed;
    while (p != -1) {
        path.push_back(p);
        p = pre[p];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}