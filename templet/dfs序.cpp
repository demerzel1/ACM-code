//l,r节点包含的子树左右边界，c线段树区间点表示的原节点序号
int l[maxn],r[maxn],c[maxn];
int tot;//dfs树节点的序号
vector<int>G[maxn];
int dfs(int x,int fa)
{
    l[x]=++tot;
    c[tot]=x;
    for(const auto &i:G[x]){
        if(i==fa)
            continue;
        dfs(i,x);
    }
    r[x]=tot;
}