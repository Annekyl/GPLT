#include "bits/stdc++.h"

using namespace std;

int get_second(string s) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    int second = stoi(s.substr(6, 2));
    return hour * 3600 + minute * 60 + second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> panda;
    for (int i = 0; i < n; i++) {
        string st, ed;
        cin >> st >> ed;
        panda.push_back({st, ed});
    }
    sort(panda.begin(), panda.end());

    multiset<int> time;
    for (int i = 0; i < n; i++) {
        string st = panda[i].first;
        string ed = panda[i].second;
        int second = get_second(st);

        auto it = time.lower_bound(second);
        if (it != time.begin()) {
            it--;
            time.erase(it);
        }
        time.insert(get_second(ed));
    }
    cout << time.size() << endl;
    return 0;
}