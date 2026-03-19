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

int x, y;
int c1, c2;
int n;

void solve() {
    cin >> x >> y;
    cin >> n;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = a + c;
        if (b == s && d != s)
            c1++;
        if (b != s && d == s)
            c2++;
        if (x < c1) {
            cout << "A" << endl;
            cout << c2 << endl;
            return;
        } else if (y < c2) {
            cout << "B" << endl;
            cout << c1 << endl;
            return;
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