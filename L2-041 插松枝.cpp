#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    stack<int> box; // 盒子
    vector<vector<int>> ans;
    vector<int> tree;
    while (box.size() || q.size()) {
        // 先从盒子里拿
        if (box.size() && (tree.empty() || tree.back() >= box.top())) {
            int t = box.top();
            box.pop();
            tree.push_back(t);
        } else if (q.size()) {
            // 然后从推送器拿
            bool suc = false;
            while (q.size()) {
                int t = q.front();
                if (tree.empty() || tree.back() >= t) {
                    q.pop();
                    tree.push_back(t);
                    suc = true;
                    break;
                } else {
                    if ((int)box.size() < m) {
                        q.pop();
                        box.push(t);
                    } else {
                        break;
                    }
                }
            }
            if (!suc) {
                ans.push_back(tree);
                tree.clear();
            }
        } else {
            // ⚠️少考虑一种情况，盒子中的松枝大小不满足要求，推送器为空，此时无限循环了
            ans.push_back(tree);
            tree.clear();
        }
        if ((int)tree.size() == k) {
            ans.push_back(tree);
            tree.clear();
        }
    }
    if (tree.size()) {
        ans.push_back(tree);
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        for (int j = 0; j < (int)ans[i].size(); j++) {
            if (j)
                cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}