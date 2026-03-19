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
constexpr int N = 110;

int n;
int a[N];
vi seat[N];
int cnt; // 已经分配好了几个学校

void solve() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int x;
        cin >> x;
        a[i] = x * 10;
    }

    int i, idx;
    for (i = 1, idx = 0; cnt < n - 1; i++) {
        // 找到当前分配座位的学校
        while (a[idx] == 0) {
            idx = (idx + 1) % n;
        }

        // 分配座位
        seat[idx].push_back(i);
        a[idx]--;
        if (a[idx] == 0) {
            cnt++;
        }

        idx = (idx + 1) % n;
    }

    // 找到当前还没有分配完座位的学校
    while (a[idx] == 0) {
        idx = (idx + 1) % n;
    }

    // 分配座位
    while (a[idx] != 0) {
        seat[idx].push_back(i);
        i += 2;
        a[idx]--;
    }

    for (int i = 0; i < n; i++) {
        cout << "#" << i + 1 << endl;
        for (int j = 0; j < seat[i].size(); j++) {
            cout << seat[i][j];
            if (j % 10 == 9)
                cout << endl;
            else
                cout << " ";
        }
        // cout << endl;
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