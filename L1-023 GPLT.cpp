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
unordered_map<char, int> cnt;

void solve() {
    cin >> s;
    for (auto &c : s) {
        if (c >= 'a' && c <= 'z')
            c -= 32;
        cnt[c]++;
    }
    // exit(1);
    while (cnt['G'] || cnt['P'] || cnt['L'] || cnt['T']) {
        if (cnt['G']) {
            cout << 'G';
            cnt['G']--;
        }
        if (cnt['P']) {
            cnt['P']--;
            cout << 'P';
        }
        if (cnt['L']) {
            cnt['L']--;
            cout << 'L';
        }
        if (cnt['T']) {
            cnt['T']--;
            cout << 'T';
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