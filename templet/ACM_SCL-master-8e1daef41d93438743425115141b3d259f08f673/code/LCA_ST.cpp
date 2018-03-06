//链式前向星
//ST<int,MAXN<<1> st;
int dfn[MAXN<<1];//欧拉序列,即dfs遍历的顺序,长度为2*n-1,下标从1开始
int id[MAXN];//点i在dfn中第一次出现的位置

int stamp;
void dfs(int u,int pre,int dep) {
    dfn[++stamp]=u;
    st.data[stamp]=dep;
    id[u]=stamp;
    for(int i=head[u]; ~i ;i = edge[i].next) {
        int v=edge[i].to;
        if(v==pre)continue;
        dfs(v,u,dep+1);
        dfn[++stamp]=u;
        st.data[stamp]=dep;
    }
}
void LCA_init(int root,int n){
    stamp=0;
    dfs(root,root,0);
    st.build(2*n-1);
}//查询LCA前的初始化,记得先调用
int query_lca(int u,int v){
    return dfn[st.query(id[u],id[v])];
}//查询u,v的lca编号