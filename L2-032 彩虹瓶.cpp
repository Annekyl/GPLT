#include "bits/stdc++.h"

using namespace std;

const int N = 110;
int n, m, k;
vector<int> a(N);

void solve(){
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int top = 1;
    stack<int> st;
    for (int i = 0; i < n; i++){
        if (a[i] == top) {
            top++;
            while (st.size() && st.top() == top) {
                st.pop();
                top++;
            }
        } else {
            st.push(a[i]);
            if (st.size() > m){
                break;
            }
        }
        // cout << top <<" " << st.top() << endl;
    }

    if (st.size()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    cin >> n >> m >> k;
    while (k--) {
        solve();
    }

    return 0;
}