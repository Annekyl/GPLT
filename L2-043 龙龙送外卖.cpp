#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int LOG = 20;

vector<vector<int>> g(N);
int root;
vector<int> depth(N, 0);
vector<int> tim(N, 0);
int time_val;
int up[N][LOG];

void dfs(int x) {
    tim[x] = time_val++;
    for (int y : g[x]) {
        depth[y] = depth[x] + 1;
        up[y][0] = x;
        for (int i = 1; i < LOG; i++) {
            up[y][i] = up[up[y][i - 1]][i - 1];
        }

        dfs(y);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    int d = depth[x] - depth[y];
    for (int i = 0; i < LOG; i++) {
        if (d >> i & 1) {
            x = up[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}

int dist2(int x, int y) { return depth[x] + depth[y] - 2 * depth[lca(x, y)]; }

int main() {
    int n, m;
    cin >> n >> m;
    int fa[n + 1];
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == -1)
            root = i;
        else
            g[x].push_back(i);
    }

    for (int i = 0; i < LOG; i++)
        up[root][i] = root;
    dfs(root);

    set<pair<int, int>> active;
    active.insert({tim[root], root});

    int sum = 0;
    int max_depth = 0;
    while (m--) {
        int x;
        cin >> x;

        max_depth = max(max_depth, depth[x]);

        auto [it, suc] = active.insert({tim[x], x});
        if (suc) {
            auto ne = next(it);
            if (ne == active.end())
                ne = active.begin();
            auto pre = (it == active.begin()) ? prev(active.end()) : prev(it);

            int u = pre->second, v = ne->second;

            sum += dist2(u, x) + dist2(x, v) - dist2(u, v);
        }

        cout << sum - max_depth << endl;
    }
    return 0;
}