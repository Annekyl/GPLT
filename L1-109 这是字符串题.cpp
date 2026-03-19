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
    string s;
    cin >> s;
    int a[30];
    int w[30];
    FOR(i, 0, 25) { cin >> w[i]; }
    memset(a, 0, sizeof a);
    for (auto &c : s) {
        a[c - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i <= 25; i++) {
        ans += a[i] * w[i];
    }
    for (int i = 0; i < 26; i++) {
        cout << a[i];
        if (i != 25)
            cout << " ";
        else
            cout << endl;
    }
    cout << ans << endl;
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