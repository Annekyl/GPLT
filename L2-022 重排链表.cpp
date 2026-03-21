#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;

struct node {
    int ne, val;
};

int main() {
    int st, n;
    cin >> st >> n;
    map<int, node> mp; // 存当前地址+（节点值+下一个节点的地址）
    for (int i = 0; i < n; i++) {
        int addr;
        node nd;
        cin >> addr >> nd.val >> nd.ne;
        mp[addr] = nd;
    }
    vector<pair<int, int>> ls; // 存当前地址+节点值
    int h = st;
    while (h != -1) {
        ls.push_back({h, mp[h].val});
        h = mp[h].ne;
    }

    vector<pair<int, int>> ans; // 存地址+值
    int l = 0, r = ls.size() - 1;   // 链表长度不一定是n，因为可能存在孤立节点，所以r=ls.size() - 1
    bool tail = true;
    while (l <= r) {
        if (tail)
            ans.push_back(ls[r--]);
        else
            ans.push_back(ls[l++]);
        tail = !tail;
    }

    for (int i = 0; i < ans.size(); i++) {  // 链表长度不一定是n，因为可能存在孤立节点，所以要＜ans.size()
        int ne = (i + 1 < ans.size() ? ans[i + 1].first : -1);
        if (ne == -1) {
            printf("%05d %d -1\n", ans[i].first, ans[i].second);
        } else {
            printf("%05d %d %05d\n", ans[i].first, ans[i].second, ne);
        }
    }

    return 0;
}
