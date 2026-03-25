#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
const int M = 1010;

int n, m;
vector<int> sex(N, -1);
vector<vector<int>> photo;

int getID(string s) {
    int x;
    if (s[0] == '-') {
        x = stoi(s.substr(1));
        sex[x] = -1;
    } else {
        x = stoi(s);
        sex[x] = 1;
    }
    return x;
}

// 计算亲密度
vector<double> calc(int person) {
    vector<double> res(n, 0);
    for (int i = 0; i < m; i++) {
        bool inPhoto = false;
        for (auto &x : photo[i])
            if (x == person) {
                inPhoto = true;
                break;
            }
        if (!inPhoto)
            continue;

        int k = photo[i].size();
        for (auto &x : photo[i]) {
            if (x != person && sex[x] != 0 && sex[x] != sex[person]) {
                res[x] += 1.0 / k;
            }
        }
    }
    return res;
}

// 关系最好的异性
vector<int> getBest(int x, vector<double> &grades) {
    double mx = 0;
    for (auto &grade : grades) {
        mx = max(mx, grade);
    }
    vector<int> res;
    for (int i = 0; i < grades.size(); i++) {
        if (mx == grades[i]) {
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    cin >> n >> m;
    photo.resize(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        photo[i].resize(k);
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            photo[i][j] = getID(s);
        }
    }

    string sa, sb;
    cin >> sa >> sb;
    int a = getID(sa);
    int b = getID(sb);

    auto calc_a = calc(a);
    auto calc_b = calc(b);

    auto best_a = getBest(a, calc_a);
    auto best_b = getBest(b, calc_b);

    bool ab = find(best_a.begin(), best_a.end(), b) != best_a.end();
    bool ba = find(best_b.begin(), best_b.end(), a) != best_b.end();

    auto fmt = [&](const int x) -> string {
        string s = (sex[x] == 1 ? "" : "-") + to_string(x);
        return s;
    };

    if (ab && ba) {
        cout << fmt(a) << " " << fmt(b) << endl;
    } else {
        for (auto &x : best_a)
            cout << fmt(a) << " " << fmt(x) << endl;
        for (auto &x : best_b)
            cout << fmt(b) << " " << fmt(x) << endl;
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}