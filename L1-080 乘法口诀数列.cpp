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
constexpr int N = 1e3 + 10;

/*
注意乘法的结果可能是0，要加一个判断，0也要加入数组
*/

int n;
vector<int> a(2);

void solve() {
    cin >> a[0] >> a[1] >> n;
    if (n == 1) {
        cout << a[0];
        return;
    }
    int idx = 0;
    while (a.size() < n) {
        int mul = a[idx] * a[idx + 1];
        vi b;
        if (mul == 0)
            b.push_back(0);
        while (mul) {
            b.push_back(mul % 10);
            mul /= 10;
        }
        while (a.size() < n && b.size()) {
            a.push_back(b.back());
            b.pop_back();
        }
        idx++;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
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