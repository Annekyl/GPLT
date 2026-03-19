#include "bits/stdc++.h"
#define int long long
// #define endl '\n'

using namespace std;

void solve() {
    vector<int> a;
    int x;
    bool suc = false;

    while (cin >> x, x != -1) {
        a.push_back(x);
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                if (a[j] != a[i])
                    continue;
                // cout << i << ":" << a[i] << endl;
                // cout << j << ":" << a[j] << endl;
                if (!suc && j + 2 < n && a[j + 1] == a[i + 1] &&
                    a[j + 2] == a[i + 2]) {
                    cout << a[i] << " " << a[i + 1] << " " << a[i + 2] << endl;
                    suc = true;
                    break;
                }
            }
            if (suc)
                break;
        }
    }

    // int n = a.size();
    // bool suc = false;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 2; j < n; j++) {
    //         if (a[j] != a[i])
    //             continue;
    //         // cout << i << ":" << a[i] << endl;
    //         // cout << j << ":" << a[j] << endl;
    //         if (j + 2 < n && a[j + 1] == a[i + 1] && a[j + 2] == a[i + 2]) {
    //             cout << a[i] << " " << a[i + 1] << " " << a[i + 2] << endl;
    //             suc = true;
    //             break;
    //         }
    //     }
    //     if (suc)
    //         break;
    // }
    if (!suc)
        cout << "NONE" << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}