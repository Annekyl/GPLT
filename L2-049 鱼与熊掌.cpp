#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n, m;
set<int> has[N]; // 拥有某种物品的人有哪些

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            has[x].insert(i);
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        vector<int> res;
        set_intersection(has[a].begin(), has[a].end(), has[b].begin(),
                         has[b].end(), back_inserter(res));
        cout << res.size() << endl;
    }
    return 0;
}
