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
要加入的位置可能在字符串末尾，需要进行判断
*/

int n;

void solve() {
    // cin >> n;
    string s;
    cin >> s;
    cin >> n;
    while (n--) {
        int st, ed;
        string s1, s2;
        cin >> st >> ed >> s1 >> s2;
        st--, ed--;
        string cat = s.substr(st, ed - st + 1);
        s.erase(st, ed - st + 1);
        auto pos = s.find(s1 + s2);
        if (pos == string::npos) {
            s += cat;
        } else {
            s.insert(pos + s1.size(), cat);
        }
        // cout << s << endl;
    }
    cout << s << endl;
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