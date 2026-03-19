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
int a[N];
vi b;
bool re = false;

void get_post(int st, int ed) {
    int i = st + 1, j = ed;
    if (!re) {
        while (i <= ed && a[i] < a[st])
            i++;
        while (j > st && a[j] >= a[st])
            j--;
    } else {
        while (i <= ed && a[i] >= a[st])
            i++;
        while (j > st && a[j] < a[st])
            j--;
    }

    if (i - j != 1)
        return;
    get_post(st + 1, j);
    get_post(i, ed);
    b.push_back(a[st]);
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    get_post(1, n);
    if (b.size() != n) {
        re = true;
        b.clear();
        get_post(1, n);
    }
    if (b.size() == n) {
        cout << "YES" << endl;
        FOR(i, 0, n - 1) {
            cout << b[i];
            if (i != n - 1)
                cout << " ";
        }
    } else {
        cout << "NO" << endl;
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