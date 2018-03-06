#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define Mod 1000000007
using ll=long long;
ll p[maxn];
ll q[maxn];

void init(){
    ll s=1;
    p[0]=1;
    for(int i=1;i<=1e6+1;i++){
        s=s*2%Mod;
        p[i]=p[i-1]+s;
    }
}

int main(){
    init();
    string s;
    cin>>s;
    int sz=s.size();
    int cnt=0;
    ll ans=0;
    for(int i=0;i<sz;i++){
        if(s[i]=='a')
            cnt++;
        if(s[i]=='b'){
            ans=(ans+p[cnt-1])%Mod;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
