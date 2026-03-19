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
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        cout << s << endl;
        int i = 0;
        // 消除多余空格
        while (1) {
            auto pos = s.find("  ");
            if (pos == string::npos) {
                break;
            } else {
                s.replace(pos, 2, " ");
            }
        }

        // 删除行首和行尾的空格
        if (s.size() && s[0] == ' ')
            s.erase(0, 1);
        if (s.size() && s[s.size() - 1] == ' ')
            s.erase(s.size() - 1, 1);

        // 删除标点符号前面的空格
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s[i] == ' ') {
                if (ispunct(s[i + 1])) {
                    s.erase(i, 1);
                    i--;
                }
            }
        }
        // 所有大写变成小写
        while (i < (int)s.size()) {
            if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'I') {
                // string c;
                // c += s[i] + 32;
                // s.replace(i, 1, c);
                s[i] = tolower(s[i]);
            }
            i++;
        }

        // 替换can you
        i = 0;
        while (i < (int)s.size()) {
            if (s[i] == 'c' && i + 6 < s.size()) {
                string temp = s.substr(i, 7);
                if (temp == "can you" &&
                    (i == 0 || s[i - 1] == ' ' || ispunct(s[i - 1])) &&
                    (i + 7 >= s.size() || s[i + 7] == ' ' ||
                     ispunct(s[i + 7]))) {
                    s.replace(i, 7, "TEMP_CAN");
                    // flag[i] = 1;
                    i += 8;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        // 替换could you
        i = 0;
        while (i < (int)s.size()) {
            if (s[i] == 'c' && i + 8 < s.size()) {
                string temp = s.substr(i, 9);
                if (temp == "could you" &&
                    (i == 0 || s[i - 1] == ' ' || ispunct(s[i - 1])) &&
                    (i + 9 >= s.size() || s[i + 9] == ' ' ||
                     ispunct(s[i + 9]))) {
                    s.replace(i, 9, "TEMP_COULD");
                    // flag[i] = 1;
                    i += 10;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        // 替换I
        i = 0;
        while (i < (int)s.size()) {
            if (s[i] == 'I' &&
                (i == 0 || s[i - 1] == ' ' || ispunct(s[i - 1])) &&
                (i + 1 >= s.size() || s[i + 1] == ' ' || ispunct(s[i + 1]))) {
                // cout << "tihuan" << endl;
                // cout << "i:" << i << endl;
                s.replace(i, 1, "you");
                i += 3;
            } else {
                i++;
            }
        }
        // 替换me
        i = 0;
        while (i < (int)s.size()) {
            if (s[i] == 'm' && i + 1 < s.size()) {
                string temp = s.substr(i, 2);
                if (temp == "me" &&
                    (i == 0 || s[i - 1] == ' ' || ispunct(s[i - 1])) &&
                    (i + 2 >= s.size() || s[i + 2] == ' ' ||
                     ispunct(s[i + 2]))) {
                    s.replace(i, 2, "you");
                    i += 3;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        // 恢复标记
        i = 0;
        while (i < (int)s.size()) {
            if (i + 7 < s.size() && s.substr(i, 8) == "TEMP_CAN") {
                s.replace(i, 8, "I can");
                i += 5;
                continue;
            }
            i++;
        }

        i = 0;
        while (i < (int)s.size()) {
            if (i + 9 < s.size() && s.substr(i, 10) == "TEMP_COULD") {
                s.replace(i, 10, "I could");
                i += 7;
                continue;
            }
            i++;
        }

        // 替换？
        while (1) {
            auto pos = s.find("?");
            if (pos == string::npos) {
                break;
            } else {
                s.replace(pos, 1, "!");
            }
        }
        cout << "AI: " << s << endl;
        // exit(0);
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