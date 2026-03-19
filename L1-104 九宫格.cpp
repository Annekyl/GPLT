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
int a[10][10];

bool check(int x, int y) {
    bool flag[10];
    memset(flag, 0, sizeof flag);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (flag[a[x + i][y + j]])
                return false;
            flag[a[x + i][y + j]] = 1;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    while (n--) {
        bool suc = true;
        FOR(i, 1, 9) {
            FOR(j, 1, 9) {
                cin >> a[i][j];
                if (a[i][j] < 1 || a[i][j] > 9)
                    suc = false;
            }
        }
        if (!suc) {
            cout << 0 << endl;
            continue;
        }
        // 每一行
        FOR(i, 1, 9) {
            bool flag[10];
            memset(flag, 0, sizeof flag);
            FOR(j, 1, 9) {
                if (flag[a[i][j]])
                    suc = false;
                if (!flag[a[i][j]])
                    flag[a[i][j]] = 1;
            }
        }
        // cout << suc << endl;
        // 每一列
        FOR(i, 1, 9) {
            bool flag[10];
            memset(flag, 0, sizeof flag);
            FOR(j, 1, 9) {
                if (flag[a[j][i]])
                    suc = false;
                if (!flag[a[j][i]])
                    flag[a[j][i]] = 1;
            }
        }

        // 每一个宫位
        for (int i = 1; i <= 9; i += 3) {
            for (int j = 1; j <= 9; j += 3) {
                if (!check(i, j)) {
                    suc = false;
                }
            }
        }
        if (suc)
            cout << 1 << endl;
        else
            cout << 0 << endl;
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