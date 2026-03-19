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

/*
price和remain都应该设为double类型的小数，int类型会出错
*/

int n;
struct node {
    double price;
    double remain;
    double avg;
    bool operator<(node &b) { return avg > b.avg; }
};

void solve() {
    int d;
    cin >> n >> d;
    vector<node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].remain;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].price;
    }
    for (int i = 0; i < n; i++) {
        a[i].avg = 1.0 * a[i].price / a[i].remain;
    }
    sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++) {
    // cout << a[i].avg << endl;
    // }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (d >= a[i].remain) {
            d -= a[i].remain;
            ans += a[i].price;
        } else {
            ans += d * a[i].avg;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
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