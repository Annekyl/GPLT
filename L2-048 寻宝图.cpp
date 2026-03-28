#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

int main() {
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = (int)(s[j] - '0');
            // cout << g[i][j] << " ";
        }
        // cout << endl;
    }

    int cnt1 = 0, cnt2 = 0;

    function<void(int, int, bool &)> dfs = [&](int x, int y,
                                               bool &suc) -> void {
        v[x][y] = true;
        if (g[x][y] > 1)    // ⚠：记得判断起点的状态是不是宝藏
            suc = true;
        // cout << "dfs:" << x << " " << y << endl;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!valid(nx, ny))
                continue;
            if (!v[nx][ny] && g[nx][ny]) {
                dfs(nx, ny, suc);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!v[i][j] && g[i][j]) {
                bool flag = false;
                dfs(i, j, flag);
                cnt1++;
                if (flag)
                    cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2 << endl;
    return 0;
}
