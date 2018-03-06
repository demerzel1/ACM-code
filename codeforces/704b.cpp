#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define maxn 5005

int n,s,e;
int nextl[maxn];
ll ans;
ll a[maxn],b[maxn],c[maxn],d[maxn],x[maxn];
ll dis[maxn][maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s>>e;
    for(int i=1;i<=n;i++)   cin>>x[i];
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   cin>>b[i];
    for(int i=1;i<=n;i++)   cin>>c[i];
    for(int i=1;i<=n;i++)   cin>>d[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(i>j) dis[i][j]=abs(x[i]-x[j])+c[i]+b[j];
                else    dis[i][j]=abs(x[i]-x[j])+d[i]+a[j];
            }
        }
    }
    ans+=dis[s][e];
    nextl[s]=e;
    for(int i=1;i<=n;i++){
        if(i==s||i==e)
            continue;
        ll sum=LLONG_MAX;
        int ind=s;
        for(int j=s;j!=e;j=nextl[j]){
            int t=nextl[j];
            if(dis[j][i]+dis[i][t]-dis[j][t]<sum){
                sum=dis[j][i]+dis[i][t]-dis[j][t];
                ind=j;
            }
        }
        int t=nextl[ind];
        nextl[ind]=i;
        nextl[i]=t;
        ans+=sum;
    }
    cout<<ans<<"\n";
    return EXIT_SUCCESS;
}
