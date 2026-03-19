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

void solve() {
    cin >> s;
    bool flag = s[0] == '-';
    int cnt = 0;
    for (auto &c : s) {
        if (c == '2')
            cnt++;
    }
    double ans = 1.0 * cnt / (s.size() - flag);
    // cout << ans << endl;
    if (flag)
        ans *= 1.5;
    if ((s[s.size() - 1] - '0') % 2 == 0)
        ans *= 2;
    // cout << ans << endl;
    printf("%.2f%%\n", ans * 100);
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