#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;

int n;
vector<int> fa(N);
vector<vector<int>> g(N);
set<int> ans;
int mx;

void dfs(int x, int depth) {
    if (mx < depth) {
        mx = depth;
        ans.clear();
        ans.insert(x);
    } else if (mx == depth) {
        ans.insert(x);
    }
    for (int y : g[x]) {
        dfs(y, depth + 1);
    }
}

int main() {
    cin >> n;
    int st;
    for (int i = 1; i <= n; i++) {
        cin >> fa[i];
        if (fa[i] == -1)
            st = i;
    }
    for (int i = 1; i <= n; i++) {
        if (fa[i] == -1)
            continue;
        g[fa[i]].push_back(i);
    }
    dfs(st, 1);
    cout << mx << endl;
    bool first = true;
    for (int x : ans) {
        if (!first)
            cout << " ";
        cout << x;
        first = false;
    }
    return 0;
}
