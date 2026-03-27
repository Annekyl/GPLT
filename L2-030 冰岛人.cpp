#include "bits/stdc++.h"
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;

int n;
map<string, pair<int, string>> mp; // 全名->(性别，父亲全名)
map<string, string> name_to_full;  // 名->全名

string check(string s1, string s2) {
    int cnt1 = 0;
    while (s1.size()) {
        int cnt2 = 0;
        string s = s2;
        while (s.size()) {
            if (s1 == s && (cnt1 < 4 || cnt2 < 4))
                return "No";
            if (cnt1 >= 4 && cnt2 >= 4)
                return "Yes";
            s = mp[s].y;
            cnt2++;
            // if (cnt2 == 4)
            //     break;
        }
        s1 = mp[s1].y;
        cnt1++;
        // if (cnt1 == 4)
        //     break;
    }
    return "Yes";
}

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        string full_name, father_name;
        int gender;
        if (s2[s2.size() - 1] == 'm') { // 男
            gender = 1;
            full_name = s1 + " " + s2.substr(0, s2.size() - 1);
            father_name = "";
            mp[full_name] = {1, father_name};
        } else if (s2[s2.size() - 1] == 'f') { // 女
            gender = 0;
            full_name = s1 + " " + s2.substr(0, s2.size() - 1);
            father_name = "";
            mp[full_name] = {0, father_name};
        } else if (s2[s2.size() - 1] == 'n') { // 男
            gender = 1;
            full_name = s1 + " " + s2.substr(0, s2.size() - 4);
            father_name = s2.substr(0, s2.size() - 4);
            mp[full_name] = {1, father_name};
        } else if (s2[s2.size() - 1] == 'r') { // 女
            gender = 0;
            full_name = s1 + " " + s2.substr(0, s2.size() - 7);
            father_name = s2.substr(0, s2.size() - 7);
            mp[full_name] = {0, father_name};
        }
        if (gender == 1)
            name_to_full[s1] = full_name;
    }
    for (auto &[full_name, s] : mp) {
        string &father_name = s.y;
        if (name_to_full.find(father_name) != name_to_full.end()) {
            father_name = name_to_full[father_name];
        } else {
            father_name = "";
        }
    }

    int m;
    cin >> m;
    while (m--) {
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        s1 = s1 + " " + s2;
        s2 = s3 + " " + s4;

        // 有人不存在
        if (mp.find(s1) == mp.end() || mp.find(s2) == mp.end()) {
            cout << "NA" << endl;
            continue;
        }

        int gender1 = mp[s1].x;
        int gender2 = mp[s2].x;
        string fa1 = mp[s1].y;
        string fa2 = mp[s2].y;

        // 两人为同性
        if (gender1 == gender2) {
            cout << "Whatever" << endl;
            continue;
        }

        cout << check(s1, s2) << endl;
    }

    return 0;
}