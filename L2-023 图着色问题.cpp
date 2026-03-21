#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 510;

int v, e, k;
vector<vector<int>> g(N);
int n;
int color[N];
bool st[N];

bool dfs(int x) {
    st[x] = true;
    for (auto &y : g[x]) {
        if (color[x] == color[y])
            return false;
        if (!st[y] && !dfs(y)) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> v >> e >> k;
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> n;
    while (n--) {
        memset(st, 0, sizeof st);
        set<int> cnt;
        for (int i = 1; i <= v; i++) {
            cin >> color[i];
            cnt.insert(color[i]);
        }
        // k种颜色
        if (cnt.size() != k) {
            cout << "No" << endl;
            continue;
        }

        // 没有相同颜色
        bool suc = true;
        for (int i = 1; i <= v; i++) {
            if (!st[i]) {
                if (!dfs(i)) {
                    suc = false;
                    break;
                }
            }
        }
        if (suc) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}