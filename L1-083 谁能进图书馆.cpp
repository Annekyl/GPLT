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
int x1, x2;
int q1, q2;

void solve() {
    // cin >> n;
    cin >> x1 >> x2 >> q1 >> q2;
    if (q1 >= x2 && q2 < x1) {
        cout << q1 << "-Y " << q2 << "-Y" << endl;
        cout << "qing 1 zhao gu hao 2" << endl;
    } else if (q2 >= x2 && q1 < x1) {
        cout << q1 << "-Y " << q2 << "-Y" << endl;
        cout << "qing 2 zhao gu hao 1" << endl;
    } else if (q1 >= x1 && q2 >= x1) {
        cout << q1 << "-Y " << q2 << "-Y" << endl;
        cout << "huan ying ru guan" << endl;
    } else if (q1 < x1 && q2 < x1) {
        cout << q1 << "-N " << q2 << "-N" << endl;
        cout << "zhang da zai lai ba" << endl;
    } else if (q1 >= x1 && q2 < x1) {
        cout << q1 << "-Y " << q2 << "-N" << endl;
        cout << "1: huan ying ru guan" << endl;
    } else if (q2 >= x1 && q1 < x1) {
        cout << q1 << "-N " << q2 << "-Y" << endl;
        cout << "2: huan ying ru guan" << endl;
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