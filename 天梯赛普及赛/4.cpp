#include "bits/stdc++.h"
#define int long long

using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i%2==0)ans+=a[i];
    }
    cout<<ans<<endl;

    return 0;
}