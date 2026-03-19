#include "bits/stdc++.h"

using namespace std;

// int w[100000];
// int ne[100000];

// int head,tail,tot;

// void add(int x){
// w[++tot]=x;
// ne[tail]=tot;
// tail=tot;
// }

/*
vector的操作：erase，insert
reverse，翻转数组
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            int l1, l2;
            cin >> l1;
            vector<int> quary(l1);
            for (int i = 0; i < l1; i++) {
                cin >> quary[i];
            }
            cin >> l2;
            vector<int> sub(l2);
            for (int i = 0; i < l2; i++) {
                cin >> sub[i];
            }
            auto it = search(a.begin(), a.end(), quary.begin(), quary.end());
            if (it == a.end()) {
                continue;
            } else {
                // a.erase(it, it + l1);
                a.erase(it, next(it, l1));            // 删除找到的片段
                a.insert(it, sub.begin(), sub.end()); // 插入新序列
            }
        } else if (k == 2) {
            // 插入平均数
            for (int i = 0; i < (int)a.size() - 1; i++) {
                if ((a[i] + a[i + 1]) % 2 == 0) {
                    a.insert(a.begin() + i + 1, (a[i] + a[i + 1]) / 2);
                    i++;
                }
            }
            // vector<int> b;
            // for (int i = 0; i < (int)a.size() - 1; i++) {
            //     b.push_back(a[i]);
            //     if ((a[i] + a[i + 1]) % 2 == 0) {
            //         b.push_back((a[i] + a[i + 1]) / 2);
            //     }
            // }
            // b.push_back(a.back());
            // a.swap(b);
        } else {
            int l, r;
            cin >> l >> r;
            reverse(a.begin() + l - 1, a.begin() + r);
        }
    }
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i];
        if (i != (int)a.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}