#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n, g, k;

struct User {
    string id;
    int grade;
    bool operator<(const User &b) const {
        if (grade != b.grade)
            return grade > b.grade;
        return id < b.id;
    }
};

void solve() {
    cin >> n >> g >> k;
    User user[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> user[i].id >> user[i].grade;
        if (user[i].grade >= 60)
            sum += user[i].grade < g ? 20 : 50;
    }
    sort(user, user + n);

    cout << sum << endl;
    int rank = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && user[i].grade < user[i - 1].grade)
            rank = i + 1;
        if (rank > k)
            break;
        cout << rank << " " << user[i].id << " " << user[i].grade << endl;
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