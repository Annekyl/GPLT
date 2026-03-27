#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    stack<char> st[n + 1];
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = (int)s.size() - 1; j >= 0; j--) {
            st[i].push(s[j]);
        }
    }

    int x;
    vector<char> ans;
    while (cin >> x, x != -1) {
        if (st[x].size()) {
            if (x == 0) {
                char t = st[0].top();
                st[0].pop();
                ans.push_back(t);
            } else {
                char t = st[x].top();
                st[x].pop();
                if (st[0].size() == s) {
                    char rem = st[0].top();
                    st[0].pop();
                    ans.push_back(rem);
                }
                st[0].push(t);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}