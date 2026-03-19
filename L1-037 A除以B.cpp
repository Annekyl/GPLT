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

void solve() {
    // cin >> n;
    int a, b;
    cin >> a >> b;
    cout << a << "/";
    if (b >= 0)
        cout << b;
    else
        cout << "(" << b << ")";
    if (b == 0)
        cout << "=Error" << endl;
    else
        printf("=%.2f", 1.0 * a / b);
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