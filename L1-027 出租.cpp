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

int n;

void solve() {
    string s;
    cin >> s;
    vector<int> a;
    set<int> st;
    for (auto &c : s) {
        st.insert(c - '0');
    }
    for (auto &x : st) {
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    unordered_map<int, int> mp;
    vector<int> idx;
    for (int i = 0; i < a.size(); i++) {
        mp[a[i]] = i;
    }
    for (auto &c : s) {
        int x = c - '0';
        idx.push_back(mp[x]);
    }
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < a.size(); i++) {
        if (i != 0)
            cout << ',';
        cout << a[i];
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (int i = 0; i < idx.size(); i++) {
        if (i != 0)
            cout << ',';
        cout << idx[i];
    }
    cout << "};" << endl;
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