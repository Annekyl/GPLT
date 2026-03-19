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

int power(int a, int p) {
    int ans = 1;
    FOR(i, 1, p) { ans *= a; }
    return ans;
}

bool check(int x) {
    int sum = 0;
    for (int i = 1;; i++) {
        sum += power(i, x);
        if (sum == n)
            return true;
        else if (sum > n)
            return false;
    }
}

void solve() {
    cin >> n;
    int ans = 32;
    while (--ans) {
        if (check(ans)) {
            break;
        }
    }

    if (ans != 0) {
        int sum = 0;
        for (int i = 1;; i++) {
            if (i != 1)
                cout << "+";
            sum += power(i, ans);
            cout << i << "^" << ans;
            if (sum == n)
                break;
        }
    } else {
        cout << "Impossible for " << n << ".";
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