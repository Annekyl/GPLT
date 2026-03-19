#include "bits/stdc++.h"

using namespace std;

int n;
vector<int> a(1e5 + 10);

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.begin() + n);

    int idx = 0; // 非负数在数组中的下标
    while (a[idx] < 0)
        idx++;
    // cout << idx << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }

    unordered_map<int, int> mp; // 某个数被删除的次数
    vector<int> ans;
    // 处理正数
    for (int i = idx; i < n; i++) {
        int val = a[i];
        // cout << val << endl;
        if (mp.find(val) == mp.end() || mp[val] == 0) {
            ans.push_back(val);
            mp[val * 2]++;
            mp[val * 5]++;
        } else {
            mp[val]--;
        }
    }
    // 处理负数
    for (int i = idx - 1; i >= 0; i--) {
        int val = a[i];
        // cout << val << endl;
        if (mp.find(val) == mp.end() || mp[val] == 0) {
            ans.push_back(val);
            mp[val * 2]++;
            mp[val * 5]++;
        } else {
            mp[val]--;
        }
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    bool first = true;
    for (auto x : ans) {
        if (!first)
            cout << " ";
        cout << x;
        first = false;
    }
    return 0;
}