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

int n;
set<string> st, ans;
vector<string> output;

void solve() {
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        FOR(i, 1, k) {
            string s;
            cin >> s;
            if (k > 1)
                st.insert(s);
        }
    }
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (st.find(s) == st.end()) {
            if (ans.find(s) == ans.end()) {
                ans.insert(s);
                output.push_back(s);
            }
        }
    }
    if (ans.size() == 0) {
        cout << "No one is handsome" << endl;
    } else {
        for (int i = 0; i < output.size(); i++) {
            cout << output[i];
            if (i < output.size() - 1)
                cout << " ";
        }
        cout << endl;
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