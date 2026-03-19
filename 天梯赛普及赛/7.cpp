#include "bits/stdc++.h"
#define int long long
// #define endl '\n'

using namespace std;

set<int> st;

bool two(int x) {
    x = x / 2;
    int num = sqrt(x);
    // cout << "2:" << x << " " << num << endl;
    if (x == num * num) {
        return true;
    } else {
        return false;
    }
}

bool check(int x, int y) { return x * x * x <= y; }

bool three(int x) {
    x /= 3;
    int l = 1, r = 2000;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        // cout<<"mid:"<<mid<<endl;
        if (check(mid, x)) {
            l = mid;
            // cout<<"l:"<<l<<endl;
        } else {
            r = mid - 1;
            // cout<<"r:"<<r<<endl;
        }
    }
    if (l * l * l == x) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int x;
    cin >> x;
    // 不是偶数
    if (x % 2) {
        cout << x << " is " << x << endl;
        return;
    }

    // 判断是不是双花数
    if (!two(x)) {
        cout << x << " is " << x << endl;
        return;
    } else {
        if (!three(x)) {
            cout << x << " is a double flower" << endl;
            return;
        } else {
            cout << x << " is a triple flower" << endl;
            return;
        }
    }
}

signed main() {
    // cout << three(648);
    // cout << endl;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}