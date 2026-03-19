#include "bits/stdc++.h"

#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 999991;
constexpr int N = 1e5 + 10;

int n;
int w[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

int m[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};

void solve() {
    cin >> n;
    bool flag = false; // 是否存在不正确的身份证
    while (n--) {
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < 17; i++) {
            char c = s[i];
            sum += (c - '0') * w[i];
        }
        sum %= 11;
        sum = m[sum];
        if (sum == 10) {
            if (s[17] != 'X') {
                cout << s << endl;
                flag = true;
            }
        } else {
            if (s[17] - '0' != sum) {
                cout << s << endl;
                flag = true;
            }
        }
    }
    if (!flag)
        cout << "All passed" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}