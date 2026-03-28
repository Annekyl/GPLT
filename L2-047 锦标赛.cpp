#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> l(20);     // 第i轮第j场比赛的败者的能力值
vector<vector<int>> max_l(20); // 第i轮第j场比赛的败者的最大能力值
vector<int> v(1 << 19);
int k;

int get(int i) { return (1 << (k - i)); }

bool dfs(int i, int j, int win) {
    if (win < l[i][j])
        return false;

    if (i == 1) {
        v[j * 2 - 1] = win;
        v[j * 2] = l[i][j];
        return true;
    }

    int left = j * 2 - 1;
    int right = j * 2;
    int loss = l[i][j];

    // 左输右赢
    if (loss >= max_l[i - 1][left] && win >= max_l[i - 1][right]) {
        if (dfs(i - 1, left, loss) && dfs(i - 1, right, win)) {
            return true;
        }
    }

    // 左赢右输
    if (win >= max_l[i - 1][left] && loss >= max_l[i - 1][right]) {
        if (dfs(i - 1, left, win) && dfs(i - 1, right, loss)) {
            return true;
        }
    }

    return false;
}

signed main() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int num = get(i);
        l[i].resize(num + 1);
        max_l[i].resize(num + 1);
        for (int j = 1; j <= num; j++) {
            cin >> l[i][j];
        }
    }

    // 自底向上预处理败者的最大能力值
    for (int i = 1; i <= k; i++) {
        int num = get(i);
        for (int j = 1; j <= num; j++) {
            max_l[i][j] = l[i][j];
            if (i != 1)
                max_l[i][j] =
                    max({l[i][j], l[i - 1][j * 2 - 1], l[i - 1][j * 2]});
        }
    }

    int w;
    cin >> w;
    if (dfs(k, 1, w)) {
        for (int i = 1; i <= (1 << k); i++) {
            if (i != 1)
                cout << " ";
            cout << v[i];
        }
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}