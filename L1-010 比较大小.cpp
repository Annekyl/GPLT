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
    constexpr int N = 1e5 + 10;

    int a, b, c;

    void solve() {
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
        if (a > c)
            swap(a, c);
        if (b > c)
            swap(b, c);
        cout << a << "->" << b << "->" << c << endl;
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