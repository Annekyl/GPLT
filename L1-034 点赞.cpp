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
unordered_map<int, int> mp;

/*
mx的更新要放在idx更新的后面
*/


void solve() {
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        FOR(i, 1, k) {
            int x;
            cin >> x;
            mp[x]++;
        }
    }
    int mx = 0, idx = 0;
    for (auto &[i, cnt] : mp) {
        if (cnt >= mx) {
            if (cnt > mx)
                idx = i;
            else
                idx = max(idx, i);
            mx = cnt;
        }
    }
    cout << idx << " " << mx << endl;
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