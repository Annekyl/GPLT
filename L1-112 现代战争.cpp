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

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        vector<int> b;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        a.push_back(b);
    }
    while (k--) {
        int mx = a[0][0];
        int x = 0, y = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                if (mx < a[i][j]) {
                    mx = a[i][j];
                    x = i, y = j;
                }
            }
        }
        // 删除所在列
        for (auto &row : a) {
            row.erase(row.begin() + y);
        }
        // 删除所在行
        a.erase(a.begin() + x);
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (j != 0)
                cout << " ";
            cout << a[i][j];
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