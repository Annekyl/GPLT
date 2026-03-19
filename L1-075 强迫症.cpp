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
    cin >> s;
    if (s.size() == 4) {
        if (stoi(s.substr(0, 2)) < 22) {
            cout << "20" << s.substr(0, 2) << "-" << s.substr(2) << endl;
        } else {
            cout << "19" << s.substr(0, 2) << "-" << s.substr(2) << endl;
        }
    } else {
        cout << s.substr(0, 4) << "-" << s.substr(4) << endl;
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