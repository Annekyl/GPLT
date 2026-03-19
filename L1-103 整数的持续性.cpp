#include "bits/stdc++.h"

// #define int long long
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

vi arr;

int count(int n) {
    int ans = 0;
    while (n >= 10) {
        ans++;
        int x = 1;
        while (n) {
            x *= n % 10;
            n /= 10;
        }
        n = x;
    }
    return ans;
}

void solve() {
    // cin >> n;
    int a, b;
    cin >> a >> b;
    // cout << count(679) << endl;
    int mx = 0;
    FOR(i, a, b) {
        int now = count(i);
        if (now > mx) {
            mx = now;
            arr.clear();
            arr.push_back(i);
        } else if (now == mx) {
            arr.push_back(i);
        }
    }
    cout << mx << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << " ";
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