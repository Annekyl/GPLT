#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    bool is_child[n + 1];
    memset(is_child, 0, sizeof is_child);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            is_child[a[i][j]] = 1;
        }
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (is_child[i] == 0) {
            root = i;
            break;
        }
    }

    queue<int> q;
    q.push(root);
    int t;
    while (q.size()) {
        t = q.front();
        q.pop();
        for (int i = 0; i < a[t].size(); i++) {
            q.push(a[t][i]);
        }
    }
    cout << t << endl;
    return 0;
}