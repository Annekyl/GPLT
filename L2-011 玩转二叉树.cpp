#include "bits/stdc++.h"
#define debug
using namespace std;

const int N = 35;

struct node {
    int val;
    struct node *left;
    struct node *right;

    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int n;
int in[35];
int pre[35];
int in_map[100];    // 不知道什么原因，以前开35可以对，现在开35是错的，以前的代码在最后面
node *root;

node *build(int pre_st, int pre_ed, int in_st, int in_ed) {
    if (in_st > in_ed)
        return nullptr;

    int val = pre[pre_st];
    node *ret = new node(val);
    int in_idx = in_map[val];
    int left_sz = in_idx - in_st;

    ret->left = build(pre_st + 1, pre_st + left_sz, in_st, in_idx - 1);
    ret->right = build(pre_st + left_sz + 1, pre_ed, in_idx + 1, in_ed);
    return ret;
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

    queue<node *> q;
    q.push(root);
    vector<int> ans;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        ans.push_back(t->val);
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }

    bool flag = true;
    for (auto x : ans) {
        if (!flag)
            cout << " ";
        cout << x;
        flag = false;
    }

    return 0;
}

#ifndef debug
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
#endif