#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;

int main() {
    int n;
    cin >> n;
    stack<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    stack<char> op;
    for (int i = 0; i < n - 1; i++) {
        char c;
        cin >> c;
        op.push(c);
    }

    while (a.size() && op.size()) {
        int n1 = a.top();
        a.pop();
        int n2 = a.top();
        a.pop();
        char c = op.top();
        op.pop();
        int res;
        switch (c) {
        case '+':
            res = n2 + n1;
            a.push(res);
            break;
        case '-':
            res = n2 - n1;
            a.push(res);
            break;
        case '*':
            res = n2 * n1;
            a.push(res);
            break;
        case '/':
            if (n1 == 0) {
                cout << "ERROR: " << n2 << "/0" << endl;
                return 0;
            }
            res = n2 / n1;
            a.push(res);
            break;
        }
    }

    cout << a.top() << endl;
    return 0;
}