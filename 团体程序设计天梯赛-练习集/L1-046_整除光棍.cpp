/*
  @pintia psid=994805046380707840 pid=994805084284633088 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 整除光棍
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805084284633088
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
int x;

bool div(int cnt, vi &ans) {
    vi a, c;
    FOR(i, 1, cnt) a.push_back(1);
    int t = 0;
    for (int i = 0; i < cnt; i++) {
        t = t * 10 + 1;
        c.push_back(t / x);
        t %= x;
    }
    if (t != 0)
        return false;
    // 去除前导零
    reverse(c.begin(), c.end());
    while (c.back() == 0)
        c.pop_back();
    reverse(c.begin(), c.end());
    ans = c;
    return true;
}

void solve() {
    cin >> x;
    int cnt = 1;
    vi ans;
    while (1) {
        if (div(cnt, ans)) {
            break;
        }
        cnt++;
    }
    for (auto &x : ans) {
        cout << x;
    }
    cout << " " << cnt << endl;
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