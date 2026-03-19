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

int y, n;

bool valid(int x, string &res) {
    string s;
    if (x < 10)
        s += "000";
    else if (x < 100)
        s += "00";
    else if (x < 1000)
        s += "0";
    s += to_string(x);
    set<char> st;
    for (auto &c : s) {
        st.insert(c);
    }
    res = s;
    return st.size() == n;
}

void solve() {
    cin >> y >> n;
    for (int i = 0; i < 10000; i++) {
        string s;
        if (valid(y + i, s)) {
            cout << i << " " << s << endl;
            break;
        }
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