/*
  @pintia psid=994805046380707840 pid=994805082313310208 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 矩阵A乘以B
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805082313310208
*/
// @pintia code=start
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
    int r1, c1, r2, c2;
    cin >> r1 >> c1;
    int a[r1 + 1][c1 + 1];

    FOR(i, 1, r1) {
        FOR(j, 1, c1) { cin >> a[i][j]; }
    }
    cin >> r2 >> c2;
    int b[r2 + 1][c2 + 1];
    FOR(i, 1, r2) {
        FOR(j, 1, c2) { cin >> b[i][j]; }
    }

    if (c1 != r2) {
        cout << "Error: " << c1 << " != " << r2 << endl;
        return;
    }
    int c[r1 + 1][c2 + 1];
    memset(c, 0, sizeof c);
    FOR(i, 1, r1) {
        FOR(j, 1, c2) {
            int ans = 0;
            FOR(k, 1, c1) { ans += a[i][k] * b[k][j]; }
            c[i][j] = ans;
        }
    }

    cout << r1 << " " << c2 << endl;
    FOR(i, 1, r1) {
        FOR(j, 1, c2) {
            cout << c[i][j];
            if (j != c2)
                cout << " ";
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
// @pintia code=end