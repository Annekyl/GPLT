#include "bits/stdc++.h"
#define int long long

using namespace std;

int n;
int a, b;
vector<int> ans;

void dfs(int num, int depth) {
    if (depth == n) {
        if (num >= a && num <= b) {
            ans.push_back(num);
        }
        return;
    }

    int ne = depth + 1;
    for (int i = 0; i < 10; i++) {
        if (ne % 2 == 0 && i % 2 != 0)
            continue;
        if (ne % 5 == 0 && i % 5 != 0)
            continue;
        if (ne == 10 && i != 0)
            continue;
        int cur = num * 10 + i;
        if (cur % ne == 0) {
            dfs(cur, ne);
        }
    }
}

signed main() {
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i <= 9; i++) {
        dfs(i, 1);
    }

    if (ans.size())
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    else
        cout << "No Solution" << endl;
    return 0;
}