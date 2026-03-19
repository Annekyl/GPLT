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
bool v[10][10];
int ans[10];

void solve() {
    FOR(i, 1, 6) {
        int x;
        cin >> x;
        v[i][x] = 1;
    }
    cin >> n;
    for (int i = 1; i <= 6; i++) {
        int cnt = 0;
        int j;
        for (j = 6; j >= 1; j--) {
            if (v[i][j])
                continue;
            cnt++;
            if (cnt == n)
                break;
        }
        cout << j;
        if (i != 6)
            cout << " ";
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