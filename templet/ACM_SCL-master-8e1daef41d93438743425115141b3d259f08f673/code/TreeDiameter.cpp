bool visited[MAXN];
int dfs(int u, int fa){//树的直径 
    visited[u]=1;
    int fi=0,se=0;
    for (int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)  continue;

        int d=dfs(v,u)+1;
        if(d>fi)     se=fi,fi=d;
        else if(d>se)se=d;
    }
    if(fi+se>ans) ans=fi+se;
    return fi;
}