#include<bits/stdc++.h>
using namespace std;
using ll=long long;
unordered_map<ll,int> mp;

int main(){
    int n;
    scanf("%d",&n);
    ll a;
    for(int i=0;i<n;i++){
        scanf("%I64d",&a);
        mp[a]++;
    }
    ll ans=0;
    for(int i=-10;i<0;i++){
        if(mp.count(i)&&mp.count(-i)){
            ans+=(ll)mp[i]*mp[-i];
        }
    }
    if(mp.count(0)){
        ans+=(ll)mp[0]*(mp[0]-1)/2;
    }
    cout<<ans;
    return 0;
}
