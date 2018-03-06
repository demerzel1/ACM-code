#include<bits/stdc++.h>
using namespace std;

const int maxn=200;

int prime[maxn],primesize,phi[maxn];
bool isprime[maxn];
void getlist(int listsize) {
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2; i<=listsize; i++) {
        if(isprime[i])prime[++primesize]=i;
        for(int j=1; j<=primesize&&i*prime[j]<=listsize; j++) {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}

int n;
int ans[20];
bool vis[20];

void dfs(int d){
    if(d==n+1&&isprime[ans[n]+1]){
        for(int i=1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<ans[n];
        cout<<"\n";
        return;
    }
    for(int i=2;i<=n;i++){
        if(!vis[i]&&isprime[ans[d-1]+i]){
            vis[i]=true;
            ans[d]=i;
            dfs(d+1);
            vis[i]=false;
        }
    }
}

int main(){
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    getlist(maxn);
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int Case=0;
    while(cin>>n){
        Case++;
        if(Case!=1)
            cout<<"\n";
        memset(ans,0,sizeof(ans));
        memset(vis,false,sizeof(vis));
        cout<<"Case "<<Case<<":\n";
        ans[1]=1;
        dfs(2);

    }
    return 0;
}
