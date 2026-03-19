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
int a[24];

void solve() {
    // cin >> n;
    for (int i = 0; i < 24; i++) {
        cin >> a[i];
    }
    int x;
    while (cin >> x) {
        if (x < 0 || x > 23)
            break;
        cout << a[x];
        if (a[x] > 50) {
            cout << " Yes" << endl;
        } else {
            cout << " No" << endl;
        }
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