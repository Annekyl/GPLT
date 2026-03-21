#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;

void solve() {
    cin >> n;
    set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }
    int m;
    cin >> m;
    vector<pair<int, string>> a;
    int avg = 0;
    for (int i = 0; i < m; i++) {
        string s;
        int val;
        cin >> s >> val;
        a.push_back({val, s});
        avg += val;
    }
    avg /= m;

    vector<string> ans;
    for (auto [val, s] : a) {
        if (val > avg && st.find(s) == st.end()) {
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());

    if (ans.size() == 0) {
        cout << "Bing Mei You" << endl;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            if (i)
                cout << endl;
            cout << ans[i];
        }
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}