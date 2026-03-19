#include "bits/stdc++.h"

using namespace std;

struct p {
    int id;
    int val, num;
    ;
};

int main() {
    int n;
    cin >> n;
    p a[n + 1];
    memset(a, 0, sizeof a);
    for (int i = 0; i <= n; i++) {
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int sum = 0;
        for (int j = 0; j < k; j++) {
            int id, val;
            cin >> id >> val;
            a[id].val += val;
            a[id].num++;
            sum += val;
        }
        a[i].val -= sum;
    }
    sort(a + 1, a + n + 1, [](p &a, p &b) {
        if (a.val == b.val) {
            return a.num != b.num ? (a.num > b.num) : (a.id < b.id);
        }
        return a.val > b.val;
    });

    for (int i = 1; i <= n; i++) {
        printf("%d %.2f\n", a[i].id, a[i].val / 100.0);
    }

    return 0;
}
