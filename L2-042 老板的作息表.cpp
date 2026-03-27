#include <bits/stdc++.h>

using namespace std;

string get_start(string &s) { return s.substr(0, 8); }

string get_end(string &s) { return s.substr(11); }

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        a[i] = s;
    }
    sort(a.begin(), a.end());

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        // cout << a[i] << endl;
        string st = get_start(a[i]);
        string ed = get_end(a[i]);
        if (i == 0) {
            if (st != "00:00:00") {
                cout << "00:00:00 - " << st << endl;
            }
        } else {
            string last_ed = get_end(a[i - 1]);
            if (last_ed != st) {
                cout << last_ed << " - " << st << endl;
            }
        }

        if (i == n - 1) {
            if (ed != "23:59:59") {
                cout << ed << " - 23:59:59" << endl;
            }
        }
    }
    return 0;
}