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
    cin >> n;
    while (n--) {
        int a, b, s1 = 0, s2 = 0;
        cin >> a >> b;
        int temp = a;
        while (temp) {
            s1 += temp % 10;
            temp /= 10;
        }
        temp = b;
        while (temp) {
            s2 += temp % 10;
            temp /= 10;
        }
        bool suc1 = a % s2 == 0;
        bool suc2 = b % s1 == 0;
        // cout << suc1 << " " << suc2;
        if (suc1 != suc2) {
            cout << (suc1 ? 'A' : 'B') << endl;
        } else {
            cout << ((a > b) ? 'A' : 'B') << endl;
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