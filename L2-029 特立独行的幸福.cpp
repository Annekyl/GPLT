#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e4 + 10;

int a, b;
bool flag[N];

int next_num(int x) {
    int res = 0;
    while (x) {
        res += (x % 10) * (x % 10);
        x /= 10;
    }
    return res;
}

bool prime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solve() {
    cin >> a >> b;
    vector<pair<int, int>> ans;
    for (int i = a; i <= b; i++) {
        set<int> path;
        int cur = i;
        while (cur != 1 && !path.count(cur)) {
            path.insert(cur);
            cur = next_num(cur);
            if (cur < N)
                flag[cur] = 1;
        }
        if (cur == 1) {
            // cout << i << endl;
            int val = path.size() * (prime(i) ? 2 : 1);
            ans.push_back({i, val});
        }
    }

    bool suc = false;
    for (auto &[pos, val] : ans) {
        if (flag[pos])
            continue;
        cout << pos << " " << val << endl;
        suc = true;
    }
    if (!suc)
        cout << "SAD" << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}