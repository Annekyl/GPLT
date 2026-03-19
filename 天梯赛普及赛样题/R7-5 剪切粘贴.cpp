#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        string c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        string add = s.substr(a, b - a + 1);
        s.erase(a, b - a + 1);
        int idx = 0;
        bool ok = false;
        while (idx < (int)s.size() && s.find(c, idx) != string::npos) {
            idx = s.find(c, idx);
            // 注意防止字符查找和字符替换越界，等于号
            if (idx + c.size() + d.size() <= s.size() &&
                s.substr(idx + c.size(), d.size()) == d) {
                s.insert(idx + c.size(), add);
                ok = true;
                break;
            } else {
                idx++; // 不能直接+c.size()，可能会跳过c字符串
                continue;
            }
        }

        if (!ok) {
            s += add;
        }
        // cout << add << " " << s << endl;
    }
    cout << s << endl;
    return 0;
}