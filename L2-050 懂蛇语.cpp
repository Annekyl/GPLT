#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n;
map<string, vector<string>> mp;

string divide(string s) {
    istringstream iss(s);
    string token;
    string res;
    while (iss >> token) {
        res += token[0];
    }
    return res;
}

int main() {
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        string d = divide(s);
        // cout << d << " " << s << endl;
        mp[d].push_back(s);
    }
    for (auto &[d, a] : mp) {
        sort(a.begin(), a.end());
    }

    int m;
    cin >> m;
    cin.ignore();
    while (m--) {
        string s;
        getline(cin, s);
        string d = divide(s);
        auto a = mp[d];
        // cout << a.size() << endl;
        if (a.size()) {
            for (int i = 0; i < a.size(); i++) {
                if (i)
                    cout << "|";
                cout << a[i];
            }
            cout << endl;
        } else {
            cout << s << endl;
        }
    }

    return 0;
}
