#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

vector<int> g[maxn];
int n,m;
int col[maxn];
bool f=true;
vector<int> ans[2];

void dfs(int u,int c){
    if(col[u]!=-1){
        if(col[u]!=c)
            f=false;
        return;
    }
    col[u]=c;
    ans[c].push_back(u);
    int sz=g[u].size();
    for(int i=0;i<sz;i++){
        if(c==0)
            dfs(g[u][i],1);
        else
            dfs(g[u][i],0);
    }
    return;
}

int main(){
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(col,-1,sizeof(col));
    for(int i=1;i<=n;i++){
        if(col[i]==-1)
            dfs(i,0);
    }
    if(!f)
        cout<<"-1";
    else{
        int sz=ans[0].size();
        cout<<sz<<"\n";
        for(int i=0;i<sz;i++){
            if(i==0)
                cout<<ans[0][i];
            else
                cout<<" "<<ans[0][i];
        }
        cout<<"\n";
        sz=ans[1].size();
        cout<<sz<<"\n";
        for(int i=0;i<sz;i++){
            if(i==0)
                cout<<ans[1][i];
            else
                cout<<" "<<ans[1][i];
        }
        cout<<"\n";
    }
    return 0;
}
