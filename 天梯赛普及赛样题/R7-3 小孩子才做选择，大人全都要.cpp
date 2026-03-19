#include "bits/stdc++.h"

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans1 = 0, ans2 = a + b;
    ans1 = a > b ? a : b;
    ans1 = ans1 > 0 ? ans1 : 0;
    if (ans2 < 0)
        ans2 = 0;
    cout << ans1 << " " << ans2 << endl;

    if (ans1 <= 0 && ans2 <= 0) {
        cout << "-_-" << endl;
        return 0;
    }

    if (ans2 > ans1)
        cout << "^_^" << endl;
    else
        cout << "T_T" << endl;

    return 0;
}