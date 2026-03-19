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
constexpr int N = 1e6 + 10;

int n;
int edge[N], ver[N], ne[N], tot;

void add(int addr, int w, int nex) {
    ver[addr] = w;
    ne[addr] = nex;
}

void solve() {
    int st;
    cin >> st >> n;
    FOR(i, 1, n) {
        int addr, x, nex;
        cin >> addr >> x >> nex;
        add(addr, x, nex);
    }
    vector<int> a, b;
    set<int> s;
    // cout << st << " " << ver[st] << " " << ne[st] << endl;
    for (int i = st; i != -1; i = ne[i]) {
        int x = abs(ver[i]);
        // cout << st << endl;
        // cout << i << " " << x << " " << ne[x] << endl;
        if (s.find(x) == s.end()) {
            // cout << "a insert" << endl;
            a.push_back(i);
            s.insert(x);
        } else {
            // cout << "b insert" << endl;
            b.push_back(i);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        int addr = a[i];
        cout << setw(5) << setfill('0') << addr << " " << ver[addr] << " ";
        if (i != a.size() - 1)
            cout << setw(5) << setfill('0') << a[i + 1] << endl;
        else
            cout << -1 << endl;
    }

    for (int i = 0; i < b.size(); i++) {
        int addr = b[i];
        cout << setw(5) << setfill('0') << addr << " " << ver[addr] << " ";
        if (i != b.size() - 1)
            cout << setw(5) << setfill('0') << b[i + 1] << endl;
        else
            cout << -1 << endl;
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