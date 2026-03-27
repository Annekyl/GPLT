#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++) {
        vector<int> a(m);
        for (int j = 0; j < m; j++) {
            cin >> a[j];
        }
        mp[a]++;
    }

    vector<pair<vector<int>, int>> res;
    for (auto &[a, cnt] : mp) {
        res.push_back({a, cnt});
    }
    sort(res.begin(), res.end(),
         [](pair<vector<int>, int> &x, pair<vector<int>, int> &y) {
             return x.second != y.second ? x.second > y.second
                                         : x.first < y.first;
         });

    cout << res.size() << endl;
    for (auto &[a, cnt] : res) {
        cout << cnt << " ";
        for (int i = 0; i < a.size(); i++) {
            if (i)
                cout << " ";
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}