#include<bits/stdc++.h>
#define maxn 3000010
using namespace std;
using ll=long long;
int phi[maxn];
void getphi() {
    phi[1]=1;
    for(int i=2; i<maxn; i++)
        phi[i]=i;
    for(int i=2; i<maxn; i++)
        if(i==phi[i])
            for(int j=i; j<maxn; j+=i)
                phi[j]=phi[j]/i*(i-1);
}
int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int a,b;
    ll ans;
    getphi();
    while(cin>>a>>b) {
        ans=0;
        for(int i=a; i<=b; i++)
            ans+=phi[i];
        cout<<ans<<"\n";
    }
    return 0;
}
