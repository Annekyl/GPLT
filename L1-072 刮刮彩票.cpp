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
int a[5][5];
int ans;
// bool flag[5][5];
int stx, sty;

void solve() {
    // cin >> n;
    FOR(i, 1, 3) {
        FOR(j, 1, 3) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                // flag[i][j] = 1;
                stx = i, sty = j;
        }
    }

    bool num[10];
    memset(num, 0, sizeof num);
    FOR(i, 1, 3) {
        FOR(j, 1, 3) { num[a[i][j]] = 1; }
    }
    for (int i = 1; i <= 9; i++) {
        if (!num[i])
            a[stx][sty] = i;
    }

    FOR(i, 1, 3) {
        int x, y;
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
    int x;
    cin >> x;
    if (x >= 1 && x <= 3) {
        ans += a[x][1] + a[x][2] + a[x][3];
    } else if (x >= 4 && x <= 6) {
        ans += a[1][x - 3] + a[2][x - 3] + a[3][x - 3];
    } else if (x == 7) {
        ans += a[1][1] + a[2][2] + a[3][3];
    } else {
        ans += a[1][3] + a[2][2] + a[3][1];
    }
    map<int, int> mp = {{6, 10000}, {7, 36},   {8, 720},   {9, 360},  {10, 80},
                        {11, 252},  {12, 108}, {19, 36},   {18, 119}, {17, 180},
                        {16, 72},   {15, 180}, {14, 54},   {13, 72},  {20, 306},
                        {21, 1080}, {22, 144}, {23, 1800}, {24, 3600}};
    cout << mp[ans] << endl;
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