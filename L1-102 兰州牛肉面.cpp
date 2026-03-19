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
    double w[n + 1];
    FOR(i, 1, n) cin >> w[i];
    int cnt[n + 1];
    memset(cnt, 0, sizeof cnt);
    int a, b;
    while (cin >> a >> b) {
        if (a == 0)
            break;
        cnt[a] += b;
    }
    double ans = 0;
    FOR(i, 1, n) {
        cout << cnt[i] << endl;
        ans += w[i] * cnt[i];
    }
    cout << fixed << setprecision(2) << ans << endl;
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