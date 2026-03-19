#include "bits/stdc++.h"

// #define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

// constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;
unordered_map<int, string> mp;
int cnt, sum;

void solve() {
    cin >> n;
    // cout << n << endl;

    int i = 0;
    while (i < n) {
        int id;
        char c;
        string s;
        cin >> id >> c >> s;
        // cout << id << " " << c << " " << s << endl;
        if (id == 0) {
            if (cnt != 0) {
                // cout << cnt << " " << sum << " ";
                cout << cnt << " " << (int)round(1.0 * sum / cnt) << endl;
            } else
                cout << "0 0" << endl;
            cnt = 0, sum = 0;
            mp.clear();
            i++;
            // cout << i << endl;
            continue;
        }

        if (c == 'S') {
            mp[id] = s;
        } else {
            if (mp.find(id) == mp.end())
                continue;
            cnt++;
            auto s1 = mp[id];
            int pos1 = s1.find(':');
            int h1 = stoi(s1.substr(0, pos1));
            int minute1 = stoi(s1.substr(pos1 + 1));

            int pos2 = s.find(':');
            int h2 = stoi(s.substr(0, pos2));
            int minute2 = stoi(s.substr(pos2 + 1));

            sum += 60 - minute1;
            sum += minute2;
            sum += (h2 - h1 - 1) * 60;
            mp.erase(mp.find(id));
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