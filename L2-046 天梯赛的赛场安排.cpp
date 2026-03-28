#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> school;

int main() {
    int n, c;
    cin >> n >> c;
    priority_queue<school> q;   // ⚠️用大根堆来维护当前学生最多的学校
    vector<string> temp;
    map<string, int> ans;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        q.push({x, s});
        temp.push_back(s);
    }

    vector<int> rooms;  // ⚠️每次要取编号最小的考场进行分配，所以不需要有序，从前到后遍历存在的考场
    int cnt = 0;
    while (q.size()) {
        auto [x, s] = q.top();
        q.pop();
        ans[s]++;
        if (x >= c) {
            cnt++;
            if (x > c)
                q.push({x - c, s});
        } else {
            int idx = -1;
            for (int i = 0; i < rooms.size(); i++) {
                if (rooms[i] >= x) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) {
                rooms.push_back(c - x);
                cnt++;
            } else {
                rooms[idx] -= x;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << temp[i] << " " << ans[temp[i]] << endl;
    }
    cout << cnt << endl;
    return 0;
}