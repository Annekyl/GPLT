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
int a[110];

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    int k;
    cin >> k;
    while (k--) {
        bool flag = false; // 是否有人猜对
        bool wa = false;   // 是否有人猜错
        FOR(i, 1, n) {
            int x;
            cin >> x;
            if (wa)
                continue;
            if (x == 0)
                continue;
            if (x != a[i])
                wa = 1;
            else
                flag = 1;
        }
        if (flag && !wa)
            cout << "Da Jiang!!!" << endl;
        else
            cout << "Ai Ya" << endl;
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