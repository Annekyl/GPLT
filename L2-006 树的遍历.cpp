#include "bits/stdc++.h"

#define int long long
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 35;

struct node {
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int n;
int in[N], post[N], pre[N];

node *build(int il, int ir, int pl, int pr) {
    if (pl > pr)
        return nullptr;

    node *root = new node(post[pr]);

    int imid = il;
    while (in[imid] != post[pr])
        imid++;

    int lnum = imid - il;
    root->left = build(il, imid - 1, pl, pl + lnum - 1);
    root->right = build(imid + 1, ir, pl + lnum, pr - 1);
    return root;
}

void solve() {
    cin >> n;
    FOR(i, 1, n) cin >> post[i];
    FOR(i, 1, n) cin >> in[i];
    node *tree = build(1, n, 1, n);
    vector<int> ans;
    queue<node *> q;
    q.push(tree);
    // cout << 1 << endl;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        ans.push_back(t->val);
        if (t->left != nullptr)
            q.push(t->left);
        if (t->right != nullptr)
            q.push(t->right);
    }
    // cout << 1 << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0)
            cout << " ";
        cout << ans[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}