#include "bits/stdc++.h"

using namespace std;

int n, m;

int fa[510];
int edge[5010][2];
bool flag[510];

void init() {
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
}

int find(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}

int merge(int x, int y) {
    if (x > y)
        swap(x, y);
    return fa[find(y)] = find(x);
}

int get_area() {
    init();
    // cout << 1 << endl;
    // cout << m << endl;
    for (int i = 0; i < m; i++) {
        int x = edge[i][0], y = edge[i][1];
        // cout << x << " " << y << endl;
        if (!flag[x] && !flag[y]) {
            // cout << "merge" << endl;
            merge(x, y);
        }
    }
    // cout << 1 << endl;

    set<int> st;
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            st.insert(find(i));
        }
    }
    // cout << 1 << endl;

    return st.size();
}

void solve() {
    memset(flag, 0, sizeof flag);
    cin >> n >> m;
    // cout << n << " " << m << endl;
    for (int i = 0; i < m; i++) {
        // cout<<"i"<<endl;
        cin >> edge[i][0] >> edge[i][1];
    }

    int k;
    int cnt = 0;
    cin >> k;
    // cout << "k:" << k << endl;
    int before = get_area();
    int after;
    while (k--) {
        // cout << cnt << endl;
        int x;
        cin >> x;
        // cout << x << endl;
        flag[x] = true;
        cnt++;
        after = get_area();
        if (before < after) {
            printf("Red Alert: City %d is lost!\n", x);
        } else {
            printf("City %d is lost.\n", x);
        }

        if (cnt == n) {
            cout << "Game Over." << endl;
        }
        before = after;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}