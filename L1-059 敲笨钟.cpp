#include "bits/stdc++.h"

#define int long long
#define endl '\n'
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

void solve() {
    cin >> n;
    cin.ignore();

    while (n--) {
        string s;
        getline(cin, s);
        // cout << s << endl;
        auto pos = s.find(',');
        string s1 = s.substr(0, pos);
        string s2 = s.substr(pos + 1);
        // cout << s1 << endl;
        // cout << s2 << endl;
        int l1 = s1.size(), l2 = s2.size();
        // cout << s1[l1 - 3] << endl;
        // cout << s1[l1 - 2] << endl;
        // cout << s1[l1 - 1] << endl;
        // cout << s2[l2 - 3] << endl;
        // cout << s2[l2 - 2] << endl;
        // cout << s2[l2 - 1] << endl;
        if (s1[l1 - 3] == 'o' && s1[l1 - 2] == 'n' && s1[l1 - 1] == 'g' &&
            s2[l2 - 4] == 'o' && s2[l2 - 3] == 'n' && s2[l2 - 2] == 'g') {
            int end = s.size() - 1;
            int cnt = 0;
            while (cnt < 3) {
                if (s[end] == ' ') {
                    cnt++;
                }
                end--;
            }
            string ans = s.substr(0, end + 2);
            ans += "qiao ben zhong.";
            cout << ans << endl;
        } else {
            cout << "Skipped" << endl;
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