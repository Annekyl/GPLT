#include "bits/stdc++.h"
#define int long long

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef map<int, double, greater<int>> Poly;

Poly readPoly() {
    int n;
    cin >> n;
    Poly res;
    for (int i = 0; i < n; i++) {
        int e;
        double c;
        cin >> e >> c;
        res[e] = c;
    }
    return res;
}

void printPoly(Poly a) {
    vector<pair<int, double>> ans;
    for (auto [e, c] : a) {
        // double c_pro = round(c * 10) / 10;
        if (fabs(c) >= 0.05) // 浮点数判断是否大于0.05
            ans.push_back({e, c});
    }
    if (ans.empty()) {
        cout << "0 0 0.0" << endl;
        return;
    }
    cout << ans.size() << " ";
    bool flag = true;   // 注意输出格式
    for (auto [e, c] : ans) {
        if (!flag)
            cout << " ";
        printf("%d %.1f", e, c);
        flag = false;
    }
    cout << endl;
}

void solve() {
    Poly a = readPoly();
    Poly b = readPoly();

    Poly ans;
    int be = b.begin()->first; // b的最高项的指数系数
    while (a.size() && a.begin()->first >= be) {
        int ae = a.begin()->first;
        double ac = a.begin()->second;
        double bc = b.begin()->second;

        int anse = ae - be; // int类型
        double ansc = ac / bc;
        ans[anse] += ansc;

        for (auto [e, c] : b) {
            a[anse + e] -= ansc * c;      // 指数为加法,整体是做减法
            if (fabs(a[anse + e]) < 1e-9) // 指数为加法,浮点数判断0
                a.erase(anse + e);        // 指数为加法
        }
    }
    printPoly(ans);
    printPoly(a);
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}