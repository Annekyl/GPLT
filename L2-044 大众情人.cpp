#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int N = 510;

int main() {
    int n;
    cin >> n;
    char gender[n + 1];
    int g[n + 1][n + 1];
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> gender[i];
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            string s;
            cin >> s;
            int pos = s.find(':');
            int y = stoi(s.substr(0, pos));
            int dist = stoi(s.substr(pos + 1));
            g[i][y] = min(dist, g[i][y]);
            // g[y][i] = min(dist, g[y][i]);
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int fur[n + 1];
    memset(fur, 0, sizeof fur);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (gender[i] != gender[j]) {
                fur[i] = max(fur[i], g[j][i]);
            }
        }
    }

    int mn_m = INF, mn_f = INF;
    for (int i = 1; i <= n; i++) {
        if (gender[i] == 'F') {
            mn_f = min(mn_f, fur[i]);
        } else {
            mn_m = min(mn_m, fur[i]);
        }
    }

    bool first = true;
    for (int i = 1; i <= n; i++) {
        if (gender[i] == 'F' && mn_f == fur[i]) {
            if (!first)
                cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << endl;
    first = true;
    for (int i = 1; i <= n; i++) {
        if (gender[i] == 'M' && mn_m == fur[i]) {
            if (!first)
                cout << " ";
            cout << i;
            first = false;
        }
    }

    return 0;
}