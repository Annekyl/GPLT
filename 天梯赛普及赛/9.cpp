#include "bits/stdc++.h"
#define int long long
// #define endl '\n'

using namespace std;

const int N = 1e4 + 10;

int n, m;
int fa[N];

void init() {
    for (int i = 0; i <= m; i++) {
        fa[i] = i;
    }
}

int find(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    if (x > y)
        swap(x, y);
    int fax = find(x), fay = find(y);
    fa[fay] = fax;
}

void solve() {
    cin >> n >> m;
    init();
    while (n--) {
        int k;
        cin >> k;
        vector<int> q;
        while (k--) {
            int x;
            cin >> x;
            q.push_back(x);
        }
        sort(q.begin(), q.end());
        for (int i = 1; i < q.size(); i++) {
            merge(q[0], q[i]);
        }
    }
    set<int> ans;
    for (int i = 1; i <= m; i++) {
        int x = find(i);
        // cout << i << ":" << x << endl;

        if (ans.find(x) == ans.end()) {
            ans.insert(x);
        } else {
        }
    }
    bool first = true;
    for (auto &x : ans) {
        if (!first)
            cout << " ";
        cout << x;
        first = false;
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