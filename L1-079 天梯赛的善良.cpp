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
int a[N];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    // FOR(i, 1, n) cout << a[i] << " ";
    // cout << endl;
    int mn = a[1];
    int mn_cnt = 1;
    int idx = 2;
    while (idx <= n && a[idx] == mn)
        idx++, mn_cnt++;
    int mx = a[n];
    int mx_cnt = 1;
    idx = n - 1;
    while (idx >= 1 && a[idx] == mx)
        idx--, mx_cnt++;
    cout << mn << " " << mn_cnt << endl;
    cout << mx << " " << mx_cnt << endl;
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