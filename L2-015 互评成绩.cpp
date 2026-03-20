#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m, k;

void solve() {
    cin >> n >> k >> m;
    vector<double> a(n, 0);
    for (int i = 0; i < n; i++) {
        int mx = -1, mn = 101;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i] += x;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        // cout<<a[i]<<" ";
        a[i] -= mx + mn;
        a[i] /= (k - 2);
    }
    // cout<<endl;
    sort(a.begin(), a.end());
    bool first = true;
    for (int i = a.size() - m; i < a.size(); i++) {
        if (!first)
            cout << " ";
        printf("%.3lf", a[i]);
        first = false;
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