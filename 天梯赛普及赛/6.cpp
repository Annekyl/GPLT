#include "bits/stdc++.h"
#define int long long
// #define endl '\n'

using namespace std;

void solve(){
    int x;
    bool flag=false;
    set<int>st;
    int ans=-1;
    while(cin>>x){
        if(x==-1){
            break;
        }
        if(st.find(x)==st.end()){
            st.insert(x);
        }else if(ans==-1){
            ans=x;
        }
    }
    if(ans==-1){
        cout<<"NONE"<<endl;
    }else{
        cout<<ans<<endl;
    }
}

signed main(){
    int t= 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}