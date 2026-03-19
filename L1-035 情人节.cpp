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
    string s, a, b;
    bool f1 = 0, f2 = 0;
    int i = 0;
    while (cin >> s) {
        if (s == ".") {
            break;
        }
        i++;
        if (i == 2) {
            a = s;
            f1 = 1;
        } else if (i == 14) {
            b = s;
            f2 = 1;
        }
    }

    if (f1 && f2) {
        cout << a << " and " << b << " are inviting you to dinner..." << endl;
    } else if (f1) {
        cout << a << " is the only one for you..." << endl;
    } else {
        cout << "Momo... No one is for you ..." << endl;
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