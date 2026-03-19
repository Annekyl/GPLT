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

int a, b;

void solve() {
    cin >> a >> b;
    int ans = 0;
    int cnt = 0;
    FOR(i, a, b) {
        if (cnt == 5) {
            cnt = 0;
            cout << endl;
        }
        ans += i;
        printf("%5d", i);
        cnt++;
    }
    printf("\nSum = %d\n", ans);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}