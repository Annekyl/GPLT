#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;

signed main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int cnt = n / 2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < cnt; i++) {
        sum1 += a[i];
    }
    for (int i = cnt; i < n; i++) {
        sum2 += a[i];
    }
    cout << "Outgoing #: " << n - cnt << endl;
    cout << "Introverted #: " << cnt << endl;
    cout << "Diff = " << sum2 - sum1 << endl;
    return 0;
}