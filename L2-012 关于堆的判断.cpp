#include "bits/stdc++.h"

using namespace std;

int n, m;
int h[5000], tot;

void insert(int val) {
    h[++tot] = val;
    int pos = tot;
    while (pos > 1 && h[pos] < h[pos / 2]) {
        swap(h[pos], h[pos / 2]);
        pos /= 2;
    }
}

int find(int val) {
    for (int i = 1; i <= tot; i++) {
        if (val == h[i])
            return i;
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    cin.ignore();
    while (m--) {
        string s;
        getline(cin, s);
        istringstream scin(s);
        vector<string> tokens;
        while (scin >> s)
            tokens.push_back(s);
        if (tokens.size() == 4) {
            int x = stoi(tokens[0]);
            if (h[1] == x) {
                cout << "T" << endl;
            } else {
                cout << "F" << endl;
            }
        } else if (tokens.size() == 5) {
            int x = stoi(tokens[0]);
            int y = stoi(tokens[2]);
            if (find(x) / 2 == find(y) / 2) {
                cout << "T" << endl;
            } else {
                cout << "F" << endl;
            }
        } else if (tokens[2] == "the") {
            int x = stoi(tokens[0]);
            int y = stoi(tokens[5]);
            if (find(x) == find(y) / 2) {
                cout << "T" << endl;
            } else {
                cout << "F" << endl;
            }
        } else {
            int x = stoi(tokens[0]);
            int y = stoi(tokens[5]);
            if (find(x) / 2 == find(y)) {
                cout << "T" << endl;
            } else {
                cout << "F" << endl;
            }
        }
    }

    return 0;
}