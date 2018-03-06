#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=1e9+7;

ll ans[10005][10];

ll mul(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2){
            res=(res*a)%M;
        }
        a=(a*a)%M;
        b/=2;
    }
    return res;
}
void init() {
    for(int i=0; i<=5; i++) {
        for(int j=1; j<=10001; j++) {
            ans[j][i]=(ans[j-1][i]+mul((ll)j,(ll)i))%M;
        }
    }
    return;
}

int main() {
    init();
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        cout<<ans[n][k]<<"\n";
    }
    return 0;
}
