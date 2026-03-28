#include "bits/stdc++.h"

using namespace std;

string s;

int main() {
    cin >> s;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(')
            stk.push(c);
        else if (c == ')') {
            string a;
            while (stk.top() != '(') {
                a += stk.top();
                stk.pop();
            }
            stk.pop();
            reverse(a.begin(), a.end());
            cout << a << endl;
        } else {
            stk.push(c);
        }
    }

    return 0;
}
