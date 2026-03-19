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

int n, k, s;
pii a[N];

void solve() {
    cin >> n >> k >> s;
    FOR(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, [](pii &a, pii &b) {
        return a.first != b.first ? a.first > b.first : a.second > b.second;
    });
    int i = 1;
    int ans = 0;
    while (i <= n) {
        int x = a[i].first, y = a[i].second;
        if (x < 175)
            break;
        ans++;
        int cnt = y >= s ? 0 : 1; // 最多推荐k个低于面试分数线的同分的人
        while (i + 1 <= n && a[i + 1].first == x) {
            i++;
            if (a[i].second >= s) {
                ans++;
            } else {
                cnt++;
                ans++;
                if (cnt == k) {
                    while (i + 1 <= n && a[i + 1].first == x)
                        i++;
                    break;
                }
            }
        }
        i++;
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