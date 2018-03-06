#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll cnt[32];
ll ans;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        int t=__builtin_popcount(x);
        ans+=cnt[t];
        cnt[t]++;
    }
    cout<<ans<<"\n";
    return 0;
}
