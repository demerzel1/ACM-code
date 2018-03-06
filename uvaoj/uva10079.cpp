#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    while(scanf("%lld",&n)&&(n>=0)){
        ll ans=n*(n+1)/2+1;
        cout<<ans<<"\n";
    }
    return 0;
}
