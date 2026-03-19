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
constexpr int N = 1e4 + 10;

string s, s2;
set<char> st;
string ans;

void solve() {
    getline(cin, s);
    getline(cin, s2);
    // cout << s << endl;
    // cout << s2 << endl;
    FOR(i, 0, s2.size() - 1) st.insert(s2[i]);
    FOR(i, 0, s.size() - 1) {
        if (st.find(s[i]) == st.end()) {
            // cout << s[i] << " ";
            ans.push_back(s[i]);
        }
    }
    cout << ans << endl;
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