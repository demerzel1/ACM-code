#include<bits/stdc++.h>
#define maxn 2000010
using namespace std;
using ll=long long;
int phi[maxn];
int dep[maxn];
void getphi() {
    phi[1]=1;
    for(int i=2; i<maxn; i++)
        phi[i]=i;
    for(int i=2; i<maxn; i++)
        if(i==phi[i])
            for(int j=i; j<maxn; j+=i)
                phi[j]=phi[j]/i*(i-1);
}

void getdep(){
    for(int i=2;i<maxn;i++){
        int cnt=1;
        int x=i;
        while(phi[x]!=1){
            x=phi[x];
            cnt++;
        }
        dep[i]=cnt;
//        if(i<=10)
//            cout<<i<<" "<<dep[i]<<"\n";
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int a,b;
    ll ans;
    getphi();
    getdep();
    int n;
    cin>>n;
    while(n--) {
        cin>>a>>b;
        ans=0;
        for(int i=a; i<=b; i++)
            ans+=dep[i];
        cout<<ans<<"\n";
    }
    return 0;
}
