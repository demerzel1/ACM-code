#include<bits/stdc++.h>
using namespace std;
#define maxn 1005

int n,m;
bool vis[maxn][maxn];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(n>m) swap(n,m);
    if(n==1) cout<<m;
    else if(n==2){
        int ans=0;
        ans+=m/4*4;
        if(m%4==0)
            cout<<ans;
        else if(m%4==1)
            cout<<ans+2;
        else
            cout<<ans+4;
    }
    else cout<<n*m-n*m/2;
    return EXIT_SUCCESS;
}
