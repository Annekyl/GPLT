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
    int a, b;
    cin >> a >> b;
    if (a == 0 || a == 1) {
        if (b == 1) {
            cout << "-" << endl;
        } else {
            cout << (a == 0 ? "biii" : "dudu") << endl;
        }
        cout << (a == 0 ? "stop" : "move") << endl;
    } else {
        cout << "-" << endl;
        cout << "move" << endl;
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