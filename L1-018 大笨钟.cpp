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

string s;

void solve() {
    cin >> s;
    int pos = s.find(':');
    int hour = stoi(s.substr(0, pos));
    int minute = stoi(s.substr(pos + 1));
    if (hour < 12 || hour == 12 && minute == 0) {
        cout << "Only " << s << ".  Too early to Dang.";
    } else if (hour == 12 && minute > 0) {
        cout << "Dang" << endl;
    } else {
        hour -= 12;
        if (minute > 0)
            hour++;
        FOR(i, 1, hour) cout << "Dang";
        cout << endl;
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