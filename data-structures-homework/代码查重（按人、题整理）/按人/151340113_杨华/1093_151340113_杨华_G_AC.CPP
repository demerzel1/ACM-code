#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

bool vis[110];
int lk[110];
vector<int>g[110];

bool dfs(int u){
    for(int i = 0;i < g[u].size();i++){
        int v = g[u][i];
        if(!vis[v]){
            vis[v] = true;
            if(lk[v] == -1 || dfs(lk[v])){
                lk[v] = u;
                return true;
            }
        }
    }
    return false;
}

int happy(int n){
    int res = 0;
    memset(lk,-1,sizeof(lk));
    for(int i = 1;i <= n;i++){
        memset(vis,false,sizeof(vis));
        if(dfs(i)){
            res++;
        }
    }
    return res;
}

int main()
{
    int n,m,k;
    while(scanf("%d %d",&n,&m) != EOF){
        scanf("%d",&k);
        for(int i = 1;i <= n;i++){
            g[i].clear();
        }
        for(int i = 1;i <= k;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
        }
        printf("%d\n",happy(n));
    }
    return 0;
}
