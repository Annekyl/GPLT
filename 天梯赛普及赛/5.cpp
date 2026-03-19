#include "bits/stdc++.h"
#define int long long
// #define endl '\n'

using namespace std;

void solve() {
    int a, b, ans;
    cin >> a >> b;
    ans = a + b;
    int add;
    int mx = 3 * 60 * 60 - 1;
    int cnt = -1;
    while (cin >> add) {
        cnt += 2;
        if (cnt >= mx && add != ans) {
            cout << add << " " << "Wrong Answer ";
            int hour = cnt / 3600;
            int minute = cnt / 60;
            int second = cnt % 60;

            printf("02:59:59\n", hour, minute, second);
            return;
        }
        if (add == ans) {
            cout << ans << " " << "Accepted ";
            // cout << cnt << endl;
            int hour = cnt / 3600;
            int minute = (cnt - hour * 60) / 60;
            int second = cnt % 60;

            printf("%02d:%02d:%02d\n", hour, minute, second);
            break;
        }
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}