#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e4 + 10;

int n;
int fa[N];
int sz[N];
int mx_id = -1;
bool flag[N];

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
}

int get(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (sz[x] < sz[y])
        swap(x, y);
    sz[x] += sz[y];
    fa[y] = x;
}

void solve() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int first;
        cin >> first;
        mx_id = max(mx_id, first);
        flag[first] = 1;
        k--;
        while (k--) {
            int x;
            cin >> x;
            merge(first, x);
            mx_id = max(mx_id, x);
            flag[x] = 1;
        }
    }

    set<int> st;
    int sum = 0;
    for (int i = 1; i <= mx_id; i++) {
        if (!flag[i])
            continue;
        int f = get(i);
        if (st.find(f) == st.end()) {
            st.insert(f);
            sum += sz[f];
        }
    }
    cout << sum << " " << st.size() << endl;

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (get(x) == get(y)) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
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