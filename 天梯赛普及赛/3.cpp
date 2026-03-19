#include "bits/stdc++.h"
#define int long long

using namespace std;

signed main(){
    int h,h1,h2;
    cin>>h>>h1>>h2;
    cout<<h<< endl;
    if(h<h1){
        cout<<"Bu Kan"<<endl;
    }else if(h<h2){
        cout<<"Zhe Gua Bao Shu Ma"<<endl;

    }else{
        cout<<"Chi Gua"<<endl;

    }

    return 0;
}