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
string a[10] = {"ling", "yi",  "er", "san", "si",
                "wu",   "liu", "qi", "ba",  "jiu"};

void solve() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '-')
            cout << "fu";
        else
            cout << a[c - '0'];
        if (i != s.size() - 1)
            cout << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}