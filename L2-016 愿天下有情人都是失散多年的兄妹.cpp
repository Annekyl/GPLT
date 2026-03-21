#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;
char sex[N];
int parent[N][2];

void dfs(int id, int depth, set<int>& st) {
    if(depth > 5 || id == -1) return;
    st.insert(id);
    dfs(parent[id][0], depth + 1, st);
    dfs(parent[id][1], depth + 1, st);
}

void solve() {
    memset(parent, -1, sizeof parent);  // 注意初始化数组
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, fa, ma;
        char s;
        cin >> id >> s >> fa >> ma;
        sex[id] = s;
        parent[id][0] = fa;
        parent[id][1] = ma;
        if (parent[id][0] != -1) sex[fa] = 'M'; // 注意记录父母亲的性别
        if (parent[id][1] != -1) sex[ma] = 'F';
    }
    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (sex[a] == sex[b]) {
            cout << "Never Mind" << endl;
            continue;
        }

        set<int>par_a, par_b;
        dfs(a, 1, par_a);
        dfs(b, 1, par_b);

        bool flag = true;
        for (auto& x: par_b) {
            if(par_a.find(x) != par_a.end()) {
                flag = false;
                break;
            }
        }

        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}