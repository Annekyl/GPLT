#include "bits/stdc++.h"

using namespace std;

const int N = 110;

int fa[N];
set<pair<int, int>> st;

void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
}

int get(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) { fa[get(x)] = get(y); }

void addEnemy(int x, int y) {
    if (x > y)
        swap(x, y);
    st.insert({x, y});
}

bool is_friend(int x, int y) { return get(x) == get(y); }

bool is_enemy(int x, int y) {
    if (x > y)
        swap(x, y);
    return st.find({x, y}) != st.end();
}

int main() {
    init();
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        // cout << m << endl;
        int a, b, c;
        cin >> a >> b >> c;
        // cout << a << b << c << endl;
        if (c == 1)
            merge(a, b);
        else
            addEnemy(a, b);
    }
    // cout << 1 << endl;

    while (k--) {
        int x, y;
        cin >> x >> y;
        bool f1 = is_friend(x, y), f2 = is_enemy(x, y);

        if (f1 && !f2)
            cout << "No problem" << endl;
        else if (f1 && f2)
            cout << "OK but..." << endl;
        else if (!f1 && f2)
            cout << "No way" << endl;
        else if (!f1 && !f2)
            cout << "OK" << endl;
    }

    return 0;
}