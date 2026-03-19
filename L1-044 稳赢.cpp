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

int k;

void win(string &s) {
    if (s == "ChuiZi") {
        cout << "Bu" << endl;
    } else if (s == "JianDao") {
        cout << "ChuiZi" << endl;
    } else {
        cout << "JianDao" << endl;
    }
}

void ping(string &s) { cout << s << endl; }

void solve() {
    cin >> k;
    // cout << k << endl;
    int i = 0;
    while (1) {
        string s;
        cin >> s;
        // cout << s << " ";
        if (s == "End")
            break;
        i++;
        // cout << i << " ";
        if (i != k + 1) {
            win(s);
        } else {
            ping(s);
            i = 0;
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