#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    string err[n];
    for (int i = 0; i < n; i++) {
        cin >> err[i];
    }
    int k;
    cin >> k;
    string s;
    // cin >> s;
    cin.ignore();
    getline(cin, s);
    int cnt = 0;
    string sub = "<censored>";
    for (int i = 0; i < n; i++) {
        while (1) {
            auto pos = s.find(err[i]);
            if (pos == string::npos)
                break;
            s.replace(pos, err[i].size(), "-_-");
            // cout << err[i] << " " << s << endl;
            cnt++;
        }
    }
    if (cnt < k) {
        while (1) {
            auto pos = s.find("-_-");
            if (pos == string::npos)
                break;
            s.replace(pos, 3, sub);
            // cout << err[i] << " " << s << endl;
            cnt++;
        }
        cout << s << endl;
    } else {
        cout << cnt << endl << "He Xie Ni Quan Jia!" << endl;
    }
    return 0;
}