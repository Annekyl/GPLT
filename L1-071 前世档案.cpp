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

int n, m;

int pow2(int k) {
    int ans = 1;
    FOR(i, 1, k) ans *= 2;
    return ans;
}

void solve() {
    cin >> n >> m;
    while (m--) {
        string s;
        cin >> s;
        // cout << s << endl;
        int ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[n - 1 - i] == 'n') {
                ans += pow2(i);
            }
            // cout << s[n - 1 - i] << " " << ans << endl;
        }
        cout << ans << endl;
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