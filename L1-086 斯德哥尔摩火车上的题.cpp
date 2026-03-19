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
    string s1, s2, ans1, ans2;
    cin >> s1 >> s2;
    for (int i = 1; i < s1.length(); i++) {
        if (s1[i] % 2 == s1[i - 1] % 2) {
            ans1 += max(s1[i], s1[i - 1]);
        }
    }
    for (int i = 1; i < s2.length(); i++) {
        if (s2[i] % 2 == s2[i - 1] % 2) {
            ans2 += max(s2[i], s2[i - 1]);
        }
    }
    if (ans1 == ans2)
        cout << ans1 << endl;
    else
        cout << ans1 << endl << ans2 << endl;
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