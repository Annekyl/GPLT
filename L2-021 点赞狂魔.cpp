#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;

struct user {
    string id;
    int total;
    int diff;
};

void solve() {
    cin >> n;
    user a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].id;
        int k;
        cin >> k;
        a[i].total = k;
        set<int> st;
        while (k--) {
            int f;
            cin >> f;
            st.insert(f);
        }
        a[i].diff = st.size();
    }
    sort(a, a + n, [](const user &a, const user &b) {
        if (a.diff != b.diff)
            return a.diff > b.diff;
        return a.total * b.diff < b.total * a.diff; // 交叉相乘
    });

    for (int i = 0; i < 3; i++) {
        if (i > 0)
            cout << " ";
        if (i < n)
            cout << a[i].id;
        else
            cout << "-";
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