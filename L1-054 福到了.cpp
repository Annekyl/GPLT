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
char c;

void solve() {
    cin >> c >> n;
    cin.ignore();
    string g[n + 1];
    char ans[n + 1][n + 1];
    FOR(i, 1, n) { getline(cin, g[i]); }
    // FOR(i, 1, n) {
    //     cout << g[i].size();
    //     cout << g[i];
    //     cout << endl;
    // }

    FOR(i, 1, n) {
        FOR(j, 1, n) { ans[i][j] = g[n - i + 1][n - j]; }
    }
    // FOR(i, 1, n) {
    //     FOR(j, 1, n) { cout << ans[i][j]; }
    //     cout << endl;
    // }
    // exit(0);
    bool flag = true;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (ans[i][j] != g[i][j - 1]) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout << "bu yong dao le" << endl;
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (ans[i][j] == '@') {
                cout << c;
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
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