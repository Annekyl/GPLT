#include "bits/stdc++.h"

// #define int long long
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

int n, m, q;

void solve() {
    cin >> n >> m >> q;
    int a[n + 10][m + 10];
    memset(a, 0, sizeof a);
    FOR(i, 1, q) {
        int t, c;
        cin >> t >> c;
        if (t == 0) {
            FOR(j, 1, m) a[c][j] = 1;
        } else
            FOR(j, 1, n) a[j][c] = 1;
    }
    int ans = 0;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (!a[i][j])
                ans++;
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