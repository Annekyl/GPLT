#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[m];
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int mx = n * (m - 1);
    if (mx >= sum) {
        cout << 0 << endl;
    } else {
        cout << sum - mx << endl;
    }
    return 0;
}