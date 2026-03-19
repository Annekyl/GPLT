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
    string s;
    int cnt = 0;
    int sum = 0;
    bool flag = false;
    int m;
    while (getline(cin, s)) {
        if (s == ".")
            break;
        sum++;
        if (s.find("chi1 huo3 guo1") != string::npos) {
            cnt++;
            if (!flag) {
                flag = 1;
                m = sum;
            }
        }
    }
    cout << sum << endl;
    if (cnt) {
        cout << m << " " << cnt << endl;
    } else {
        cout << "-_-#" << endl;
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