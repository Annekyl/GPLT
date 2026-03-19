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
set<int> s[55];

/*
并集的计算通过两个集合的和减去交集得到，否则的话会超时
*/

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        FOR(j, 1, m) {
            int x;
            cin >> x;
            s[i].insert(x);
        }
    }
    // cout<<1<<endl;
    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        set<int> same, all;
        // cout << x << ":";
        for (auto &num : s[x]) {
            // cout << num << " ";
            // all.insert(num);
            if (s[y].find(num) != s[y].end()) {
                same.insert(num);
            }
        }
        // cout << endl;
        // for (auto &num : s[y]) {
        //     all.insert(num);
        // }
        // cout << same.size() << endl;
        // cout << all.size() << endl;
        cout << setprecision(2) << fixed
             << 100.0 * same.size() / (s[x].size() + s[y].size() - same.size())
             << "%" << endl;
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