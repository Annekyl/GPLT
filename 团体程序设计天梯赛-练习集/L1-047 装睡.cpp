/*
  @pintia psid=994805046380707840 pid=994805083282194432 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 装睡
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805083282194432
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
    cin >> n;
    FOR(i, 1, n) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (15 <= x && x <= 20 && 50 <= y && y <= 70) {
            continue;
        } else {
            cout << s << endl;
        }
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