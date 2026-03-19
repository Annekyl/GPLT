#include "bits/stdc++.h"

using namespace std;

int main() {
    int x;
    int cnt = 1;
    bool flag = false;
    int ans = 0;
    while (cin >> x) {
        if (!flag && x == 250) {
            ans = cnt;
            flag = 1;
        }
        cnt++;
    }
    cout << ans << endl;

    return 0;
}