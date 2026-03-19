#include "bits/stdc++.h"
#define int long long
#define endl '\n'

using namespace std;

int func(int n) {
    if (n <= 1) {
        return 1;
    }
    int a = 1, b = 1;
    int ret;
    for (int i = 2; i <= n; i++) {
        ret = a + b;
        b = a;
        a = ret;
    }
    return ret;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<func(5);
    // int t = 1;
    // // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}