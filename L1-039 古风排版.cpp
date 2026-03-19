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
constexpr int N = 1010;

/*
memset初始化数组时要初始化为空格，而不是\0
*/

int n;
string s;
char a[N][N];

void solve() {
    memset(a, ' ', sizeof a);
    cin >> n;
    cin.ignore();
    getline(cin, s);
    int col = (s.size() + n - 1) / n;
    int r = 1, c = col;
    for (auto &ch : s) {
        a[r][c] = ch;
        r++;
        if (r > n) {
            r = 1;
            c--;
        }
    }
    FOR(i, 1, n) {
        FOR(j, 1, col) { cout << a[i][j]; }
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