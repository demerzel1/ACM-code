#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m,t;
ll ans;
ll gao(ll a,ll b){
    ll t=1;
    for(int i=1;i<=b;i++){
        t*=a-i+1;
        t/=i;
    }
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t;
    for(int i=4;i<t;i++){
        ans+=gao(n,i)*gao(m,t-i);
    }
    cout<<ans;
    return 0;
}
