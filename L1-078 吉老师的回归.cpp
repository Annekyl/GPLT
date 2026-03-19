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

int n, m;

void solve() {
    cin >> n >> m;
    cin.ignore();
    vector<string> a;
    while (n--) {
        string s;
        // cin >> s;
        getline(cin, s);
        if (s.find("qiandao") != string::npos ||
            s.find("easy") != string::npos) {
            continue;
        }
        a.push_back(s);
    }
    if (m >= a.size()) {
        cout << "Wo AK le" << endl;
    } else {
        cout << a[m] << endl;
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