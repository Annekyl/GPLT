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
constexpr int N = 110;

/*
注意最后的输入，要判断整数部分为0，分数部分为0，以及整数部分和分数部分同时为0这三种特殊情况
*/

int n;
string s[N];
int up[N], down[N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

void solve() {
    cin >> n;
    int sum_down = 1; // 记录最终所有式子分母的最小公倍数
    FOR(i, 1, n) {
        cin >> s[i];
        int pos = s[i].find('/');
        up[i] = stoi(s[i].substr(0, pos));
        down[i] = stoi(s[i].substr(pos + 1));
        sum_down = lcm(sum_down, down[i]);
    }
    // cout << sum_down;
    int sum_up = 0;
    FOR(i, 1, n) sum_up += up[i] * (sum_down / down[i]);

    int integer = sum_up / sum_down;
    sum_up %= sum_down;
    int temp = gcd(sum_up, sum_down);
    sum_up /= temp;
    sum_down /= temp;
    if (integer == 0 && sum_up == 0) {
        cout << 0 << endl;
    } else if (integer == 0) {
        cout << sum_up << "/" << sum_down << endl;
    } else if (sum_up == 0) {
        cout << integer << endl;
    } else {
        cout << integer << " ";
        cout << sum_up << "/" << sum_down << endl;
    }
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