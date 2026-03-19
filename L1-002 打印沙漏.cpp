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

int n;
char c;

bool check(int x) { return x * x * 2 - 1 <= n; }

void solve() {
    cin >> n >> c;
    int rol;
    int l = 1, r = 50;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    int row = l;

    REF(i, row, 1) {
        int cnt = i * 2 - 1;
        FOR(j, 1, l - i) cout << " ";
        FOR(j, 1, cnt) cout << c;
        // FOR(j, 1, l - i) cout << " ";
        cout << endl;
    }
    FOR(i, 2, row) {
        int cnt = i * 2 - 1;
        FOR(j, 1, l - i) cout << " ";
        FOR(j, 1, cnt) cout << c;
        // FOR(j, 1, l - i) cout << " ";
        cout << endl;
    }
    cout << n - row * row * 2 + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}