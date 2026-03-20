#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
vi tail;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int l = 0, r = tail.size();
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) {
            tail.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << tail.size() << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}