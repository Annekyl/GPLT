#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

int n, L;
int ans = 0;

vector<int> colrem(10);

void dfs(int x, int y, int rowrem) {
    int nx = ((y == n - 1) ? x + 1 : x);
    int ny = ((y == n - 1) ? 0 : y + 1);
    // cout << x << " " << y << " " << nx << " " << ny << endl;
    // 右下角
    if (x == n - 1 && y == n - 1) {
        if (colrem[y] == rowrem) {
            ans++;
        }
        return;
    }

    // 最后一列
    if (y == n - 1) {
        if (colrem[y] >= rowrem) {
            colrem[y] -= rowrem;
            dfs(nx, ny, L);
            colrem[y] += rowrem;
        }
        return;
    }

    // 最后一行
    if (x == n - 1) {
        if (colrem[y] <= rowrem) {
            dfs(nx, ny, rowrem - colrem[y]);
        }
        return;
    }

    // 普通情况
    for (int i = 0; i <= min(rowrem, colrem[y]); i++) {
        colrem[y] -= i;
        dfs(nx, ny, rowrem - i);
        colrem[y] += i;
    }
}

int main() {
    cin >> L >> n;
    fill(colrem.begin(), colrem.end(), L);
    dfs(0, 0, L);
    cout << ans << endl;
    return 0;
}
