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
    cin >> n;
    while (n--) {
        int h, w;
        double t;
        cin >> h >> w;
        t = (h - 100) * 0.9 * 2;
        // cout << t << endl;
        if (abs(w - t) < t * 0.1) {
            cout << "You are wan mei!" << endl;
        } else if (w > t) {
            cout << "You are tai pang le!" << endl;
        } else {
            cout << "You are tai shou le!" << endl;
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