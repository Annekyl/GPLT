#include "bits/stdc++.h"

using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};
int n;
int pre[35];
int in[35];
int in_map[34];
node *root;

node *build(int prest, int preed, int inst, int ined) {
    if (inst > ined)
        return nullptr;

    int val = pre[prest];
    node *root = new node(val);

    int idx = in_map[val];
    int left_sz = idx - inst;

    // 左：前序遍历[prest+1,prest+left_sz], 中序遍历[inst,idx-1]
    root->left = build(prest + 1, prest + left_sz, inst, idx - 1);
    // 右：前序遍历[prest+left_sz+1,preed], 中序遍历[idx+1,ined]
    root->right = build(prest + left_sz + 1, preed, idx + 1, ined);

    return root;
}

void reverse(node *root) {
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        in_map[in[i]] = i;
    }
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    root = build(0, n - 1, 0, n - 1);
    reverse(root);
    vector<int> level;
    queue<node *> q;
    q.push(root);
    while (q.size()) {
        auto top = q.front();
        q.pop();
        level.push_back(top->val);
        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);
    }
    bool first = true;
    for (auto x : level) {
        if (!first)
            cout << " ";
        cout << x;
        first = false;
    }

    return 0;
}