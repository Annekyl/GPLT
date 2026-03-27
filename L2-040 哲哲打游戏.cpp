#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        g[i].resize(k + 1);
        for (int j = 1; j <= k; j++) {
            cin >> g[i][j];
        }
    }

    vector<int> rec(110); // 存档
    int cur = 1;          // 当前位置

    auto solve0 = [&](int x) -> void { cur = g[cur][x]; };
    auto solve1 = [&](int x) -> void {
        rec[x] = cur;
        cout << cur << endl;
    };
    auto solve2 = [&](int x) -> void { cur = rec[x]; };

    while (m--) {
        int op, x;
        cin >> op >> x;
        if (op == 0)
            solve0(x);
        else if (op == 1)
            solve1(x);
        else
            solve2(x);
    }
    cout << cur << endl;
    return 0;
}