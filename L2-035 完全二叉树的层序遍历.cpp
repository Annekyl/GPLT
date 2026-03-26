#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> level(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    function<void(int)> build = [&](int idx) -> void {
        if (idx > n)
            return;
        build(idx * 2);
        build(idx * 2 + 1);
        level[idx] = a[cur++];
    };

    build(1);
    for (int i = 1; i <= n; i++) {
        cout << level[i];
        if (i != n)
            cout << " ";
    }

    return 0;
}