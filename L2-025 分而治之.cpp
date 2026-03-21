#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e4 + 10;

int n, m;
vector<vector<int>> g(N);
bool loss[N];

void solve2() {
    memset(loss, 0, sizeof loss);
    int np;
    cin >> np;
    for (int i = 0; i < np; i++) {
        int x;
        cin >> x;
        loss[x] = true;
    }
    bool suc = true;
    for (int i = 1; i <= n; i++) {
        if (loss[i])
            continue;
        for (auto &y : g[i]) {
            if (!loss[y]) {
                suc = false;
                break;
            }
        }
        if (!suc)
            break;
    }
    if (suc) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int k;
    cin >> k;
    while (k--) {
        solve2();
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