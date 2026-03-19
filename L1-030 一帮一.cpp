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
constexpr int N = 55;

int n;
;
pair<int, string> a[N];
bool v[N];
int idx;

void solve() {
    cin >> n;
    FOR(i, 1, n) {
        int id;
        string s;
        cin >> id >> s;
        a[i] = make_pair(id, s);
    }

    idx = n;
    FOR(i, 1, n) {
        if (v[i])
            continue;
        cout << a[i].second << " ";
        v[i] = 1;
        REF(j, idx, 1) {
            if (!v[j] && a[j].first != a[i].first) {
                cout << a[j].second << endl;
                v[j] = 1;
                break;
            }
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