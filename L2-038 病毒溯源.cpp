#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<bool> v(n, false);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            g[i].push_back(x);
            v[x] = true;
        }
        sort(g[i].begin(), g[i].end());
    }
    int st;
    for (int i = 0; i < n; i++) {
        if (!v[i])
            st = i;
    }

    int mx_depth = 0;
    vector<int> ans;
    function<void(int, int, vector<int> &)> dfs =
        [&](int x, int depth, vector<int> &path) -> void {
        // 更新答案
        if (depth > mx_depth) {
            mx_depth = depth;
            ans = path;
        }

        for (auto y : g[x]) {
            path.push_back(y);
            dfs(y, depth + 1, path);
            path.pop_back();
        }
    };
    vector<int> path;
    path.push_back(st);
    dfs(st, 1, path);

    cout << mx_depth << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i)
            cout << " ";
        cout << ans[i];
    }
    return 0;
}