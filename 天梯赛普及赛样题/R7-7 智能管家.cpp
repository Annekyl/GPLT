#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    while (k--) {
        int x;
        vector<int> cnt(m + 1, 0);
        while (cin >> x, x) {
            cnt[a[x - 1]]++;
        }
        bool first = true;
        for (int i = 1; i <= m; i++) {
            if (!cnt[i])
                continue;
            if (!first)
                cout << " ";
            cout << "B" << i << "-" << cnt[i];
            first = false;
        }
        cout << endl;
    }

    return 0;
}