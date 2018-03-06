#include<bits/stdc++.h>
using namespace std;
#define maxn 50005
vector<int> mp[maxn];
int n,r1,r2;
bool vis[maxn];
int ans[maxn];

void dfs(int x){
    vis[x]=true;
    int sz=mp[x].size();
    for(int i=0;i<sz;i++){
        if(!vis[mp[x][i]]){
            ans[mp[x][i]]=x;
            dfs(mp[x][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>r1>>r2;
    for(int i=1;i<=n;i++){
        if(i!=r1){
            int x;
            cin>>x;
            mp[i].push_back(x);
            mp[x].push_back(i);
        }
    }
    dfs(r2);
    for(int i=1;i<=n;i++){
        if(i!=r2)
            cout<<ans[i]<<" ";
    }
    return 0;
}
