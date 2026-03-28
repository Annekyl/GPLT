#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n;

int main() {
    cin >> n;
    set<int> svx0;
    set<int> svx1;
    set<int> svx2;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0)
            svx0.insert(x);
        if (y == 1)
            svx1.insert(x);
        if (y == 2)
            svx2.insert(x);
    }

    vector<int> vx0(svx0.begin(), svx0.end());
    vector<int> vx1(svx1.begin(), svx1.end());
    vector<int> vx2(svx2.begin(), svx2.end());

    int cnt = 0;
    for (int x1 : vx1) {
        int target = 2 * x1;
        int i = 0;
        int j = vx2.size() - 1;
        while (i < vx0.size() && j >= 0) {
            int sum = vx0[i] + vx2[j];
            if (sum == target) {
                printf("[%d, 0] [%d, 1] [%d, 2]\n", vx0[i], x1, vx2[j]);
                cnt++;
                i++;
                j--;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
    }
    if (cnt == 0)
        cout << "-1" << endl;

    return 0;
}
