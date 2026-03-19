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

int a, b, n;

void solve() {
    cin >> a >> b >> n;
    bool suc = false;
    int dif = INF;
    int ans1, ans2;
    FOR(i, 1, n - 1) {
        int x = i, y = n - i;
        if (a % x == 0 && b % y == 0) {
            if (a / x < 2 || b / y < 2)
                continue;
            // cout << x << " " << y << endl;
            // return;
            suc = 1;
            if (abs(a / x - b / y) < dif) {
                dif = abs(a / x - b / y);
                ans1 = x, ans2 = y;
            }
        }
    }
    if (!suc) {
        cout << "No Solution" << endl;
    } else {
        cout << ans1 << " " << ans2 << endl;
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