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

void solve() {
    // cin >> n;
    int mx, s, t;
    cin >> mx >> s >> t;
    if (mx > 35 && s == 1 && t >= 33) {
        cout << "Bu Tie" << endl;
        cout << mx << endl;
    } else {
        if (mx > 35 && t >= 33 && s == 0) {
            cout << "Shi Nei" << endl;
            cout << mx << endl;
        } else if (s == 1 && (mx < 35 || t < 33)) {
            cout << "Bu Re" << endl;
            cout << t << endl;
        } else if (s == 0 && (mx < 35 || t < 33)) {
            cout << "Shu Shi" << endl;
            cout << t << endl;
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