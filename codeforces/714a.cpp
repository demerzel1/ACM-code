#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l1,l2,r1,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    ll minn=min(r1,r2);
    ll maxn=max(l1,l2);
    ll ans=minn-maxn+1;
    if(maxn>minn){
        cout<<0;
        return 0;
    }
    if(k>=maxn&&k<=minn){
        ans--;
    }
    cout<<ans;
    return 0;
}
