#include "bits/stdc++.h"

#define int long long
#define endl '\n'
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

void solve() {
    cin >> n;
    while (n--) {
        int sex, h, w;
        cin >> sex >> h >> w;
        if (sex == 1) {
            if (h > 130) {
                cout << "ni li hai!";
            } else if (h == 130) {
                cout << "wan mei!";
            } else {
                cout << "duo chi yu!";
            }
            cout << " ";
            if (w > 27) {
                cout << "shao chi rou!";
            } else if (w == 27) {
                cout << "wan mei!";
            } else {
                cout << "duo chi rou!";
            }
        } else {
            if (h > 129) {
                cout << "ni li hai!";
            } else if (h == 129) {
                cout << "wan mei!";
            } else {
                cout << "duo chi yu!";
            }
            cout << " ";
            if (w > 25) {
                cout << "shao chi rou!";
            } else if (w == 25) {
                cout << "wan mei!";
            } else {
                cout << "duo chi rou!";
            }
        }
        cout << endl;
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