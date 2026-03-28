#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n;
int root;
vector<int> g[N];

void dfs(int x, int &sz, bool &suc) {
    if (g[x].size() != sz) {
        sz = max((int)g[x].size(), sz);
        suc = false;
    }
    for (auto y : g[x]) {
        if (g[y].size())
            dfs(y, sz, suc);
    }
}

void preOrder(int x, int &cnt) {
    if (cnt)
        cout << " ";
    cout << x;
    cnt++;
    for (auto y : g[x]) {
        preOrder(y, cnt);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x)
            g[x].push_back(i);
        else
            root = i;
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    bool suc = true;
    int sz = g[root].size();
    dfs(root, sz, suc);
    cout << sz << " " << (suc ? "yes" : "no") << endl;
    int cnt = 0;
    preOrder(root, cnt);

    return 0;
}
