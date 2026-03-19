#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int n = s.size();
    int ans = 1;
    // 奇数个
    for (int i = 1; i < n; i++) {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        int len = r - l - 1;
        ans = max(ans, len);
    }
    // 偶数个
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        int len = r - l - 1;
        ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}