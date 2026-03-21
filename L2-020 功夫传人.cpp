#include "bits/stdc++.h"

// #define int long long
#define endl '\n'
using namespace std;

typedef long long ll;

constexpr int N = 1e5 + 10;

int n;
double z, r;
vector<vector<int>> a(N);
bool suc[N];
int mul[N];
double ans = 0;

void dfs(int x, double val) {
    // cout << x << ":" << val << endl;
    if (suc[x]) {
        // cout << "suc" << endl;
        ans += val * mul[x];
        return;
    }
    for (auto y : a[x]) {
        // cout << y << endl;
        dfs(y, val * r);
    }
}

void solve() {
    memset(suc, 0, sizeof suc);
    // cout << 18 * 0.98 * 16 + 18 * 0.97 * 7;
    cin >> n >> z >> r;
    r = (100 - r) / 100;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 0) {
            suc[i] = true;
            int x;
            cin >> x;
            mul[i] = x;
            continue;
        }
        while (k--) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ":";
    //     for (auto x : a[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    dfs(0, z);
    cout << (int)ans << endl;
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