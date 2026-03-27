#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    vector<vector<int>> ans;
    vector<int> tow1;
    vector<int> tow2;
    tow1.push_back(q.front());
    q.pop();
    while (q.size()) {
        int t = q.front();
        q.pop();
        if (t < tow1.back()) {
            tow1.push_back(t);
        } else {
            if (tow2.empty() || t > tow2.back()) {
                tow2.push_back(t);
            } else {
                ans.push_back(tow1);
                tow1.clear();
                while (tow2.size() && tow2.back() > t) {
                    tow1.push_back(tow2.back());
                    tow2.pop_back();
                }
                tow1.push_back(t);
            }
        }
    }
    if (tow1.size())
        ans.push_back(tow1);
    if (tow2.size())
        ans.push_back(tow2);

    cout << ans.size() << " ";
    int mx = 0;
    for (int i = 0; i < ans.size(); i++) {
        mx = max(mx, (int)ans[i].size());
    }
    cout << mx;

    return 0;
}