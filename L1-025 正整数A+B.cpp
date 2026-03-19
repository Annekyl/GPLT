#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

string s;

bool valid(string &s, int &num) {
    if (s.empty())
        return false;
    int x = 0;
    for (auto &c : s) {
        if (c < '0' || c > '9') {
            return false;
        }
        x = x * 10 + (c - '0');
        if (x > 1000)
            return false;
    }
    if (x < 1 || x > 1000)
        return false;
    num = x;
    return true;
}

void solve() {
    string s;
    getline(cin, s);
    int pos = s.find(' ');
    string s1 = s.substr(0, pos);
    string s2 = s.substr(pos + 1);

    int num1, num2;
    bool f1 = valid(s1, num1);
    bool f2 = valid(s2, num2);
    if (f1 && f2) {
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    } else if (f1 && !f2) {
        cout << num1 << " + " << "?" << " = " << "?" << endl;
    } else if (!f1 && f2) {
        cout << "?" << " + " << num2 << " = " << "?" << endl;
    } else if (!f1 && !f2) {
        cout << "?" << " + " << "?" << " = " << "?" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}