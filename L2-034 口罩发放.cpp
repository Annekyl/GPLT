#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int d, p;

bool comp(string t1, string t2) {
    int hour1 = stoi(t1.substr(0, 2));
    int minute1 = stoi(t1.substr(3, 2));
    int hour2 = stoi(t2.substr(0, 2));
    int minute2 = stoi(t2.substr(3, 2));
    if (hour1 != hour2)
        return hour1 < hour2;
    else
        return minute1 < minute2;
}

struct User {
    string name;
    string id;
    int status;
    string time;
    bool operator<(const User b) const { return comp(time, b.time); }
};
map<string, int> mp; // 记录这个人最后一次发放口罩是在第几天
vector<pair<string, string>> st;    // ⚠️要用vector来存，因为set会破坏顺序，然后再加一个set来去重
set<string> uniq;

bool valid(string id) {
    if (id.size() != 18)
        return false;
    for (char c : id)
        if (!isdigit(c))
            return false;
    return true;
}

int main() {
    cin >> d >> p;
    for (int i = 1; i <= d; i++) {
        int t, s;
        cin >> t >> s;
        vector<User> user;
        for (int j = 0; j < t; j++) {
            string name, id, time;
            int status;
            cin >> name >> id >> status >> time;
            if (!valid(id))
                continue;
            user.push_back({name, id, status, time});
            if (status == 1) {
                if (uniq.find(id) == uniq.end()) {
                    st.push_back({name, id});
                    uniq.insert(id);
                }
            }
        }
        stable_sort(user.begin(), user.end());  // ⚠️要用稳定排序

        int cnt = 0; // 记录已经发放了多少口罩
        for (int j = 0; j < user.size() && cnt < s; j++) {
            if (mp.find(user[j].id) == mp.end()) {
                cout << user[j].name << " " << user[j].id << endl;
                mp.insert({user[j].id, i});
                cnt++;
            } else if (mp[user[j].id] < i - p) {
                cout << user[j].name << " " << user[j].id << endl;
                mp[user[j].id] = i;
                cnt++;
            }
        }
    }
    for (auto [name, id] : st) {
        cout << name << " " << id << endl;
    }
    return 0;
}