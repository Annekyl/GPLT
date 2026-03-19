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

int a[5], mn, md;

void solve() {
    cin >> a[1] >> a[2] >> a[3] >> a[4] >> mn >> md;
    int cnt = 0;
    int mx = a[1];
    int warning;
    for (int i = 1; i <= 4; i++) {
        if (a[i] < mn)
            cnt++, warning = i;
        if (a[i] > mx)
            mx = a[i];
    }
    FOR(i, 1, 4) {
        if (mx - a[i] > md)
            cnt++, warning = i;
    }
    if (cnt > 1) {
        cout << "Warning: please check all the tires!" << endl;
    } else if (cnt == 1) {
        cout << "Warning: please check #" << warning << "!" << endl;
    } else {
        cout << "Normal" << endl;
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