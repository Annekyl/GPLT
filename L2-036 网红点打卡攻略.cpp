#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    int g[n + 1][n + 1];
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
        g[y][x] = min(g[y][x], z);
    }
    int k;
    cin >> k;
    int ans = 0; // 有效攻略的数量
    int mn_cost = INF;
    int mn_idx;
    for (int i = 1; i <= k; i++) {
        int N;
        cin >> N;
        vector<int> path(N); // 旅游路径
        vector<bool> v(n + 1, false);
        bool suc = true;

        // 每个地点仅去一次
        for (int j = 0; j < N; j++) {
            cin >> path[j];
            if (v[path[j]])
                suc = false;
            v[path[j]] = 1;
        }
        if (!suc || path.size() != n)
            continue;

        int cost = 0;
        for (int j = 0; j <= N; j++) {
            int x, y;
            if (j == 0)
                x = 0, y = path[j];
            else if (j == N)
                x = path[j - 1], y = 0;
            else
                x = path[j - 1], y = path[j];
            if (g[x][y] == INF) {
                suc = false;
                break;
            }
            cost += g[x][y];
        }
        if (!suc)
            continue;
        ans++;
        if (mn_cost > cost) {
            mn_cost = cost;
            mn_idx = i;
        }
    }
    cout << ans << endl;
    cout << mn_idx << " " << mn_cost << endl;
    return 0;
}