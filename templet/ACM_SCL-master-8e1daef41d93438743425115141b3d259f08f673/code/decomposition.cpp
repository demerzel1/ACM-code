template<typename T>
struct TreeDecomposition{
    Segtree<T> gao;
    struct e{
        int u,v;T c;
        e(){}
        e(int x,int y,T z):u(x),v(y),c(z){}
    };
    vector<int>tree[MAXN];
    vector<e>edge;
    int fa[MAXN];//父亲节点
    int son[MAXN];//重儿子
    int dep[MAXN];//深度
    int sz[MAXN];//以v为根的子树的节点数
    int top[MAXN];//v所在的重链的顶端节点
    int p[MAXN];//v与其父亲节点的连边在线段树中的位置
    int fp[MAXN];//和p数组相反,debug用
    int pos;
    TreeDecomposition(){
        pos=-1;
        memset(son,-1,sizeof(son));
    }
    void addedge(int u,int v,T c){
        edge.emplace_back(u,v,c);
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    void dfs(int u,int f,int d){
        dep[u]=d;fa[u]=f;sz[u]=1;
        for(const auto&v:tree[u]){
            if(v!=f){
                dfs(v,u,d+1);
                sz[u]+=sz[v];
                if(son[u]==-1 || sz[v]>sz[son[u]])
                    son[u]=v;
            }
        }
    }//第一遍dfs求出fa,dep,sz,son
    void decomposition(int u,int sp){
        top[u]=sp;p[u]=++pos;fp[p[u]]=u;
        if(son[u]==-1) return;
        decomposition(son[u],sp);
        for(const auto&v:tree[u]){
            if(v!=son[u] && v!=fa[u]){
                decomposition(v,v);
            }
        }
    }//第二遍dfs求出top和p,fp
    void solve(){
        dfs(1,0,0);
        decomposition(1,1);
        gao.build(1,1,pos);
        for(auto&&t:edge){
            if(dep[t.u]>dep[t.v]) swap(t.u,t.v);
            gao.update(1,1,pos,p[t.v],t.c);
        }
    }
    int LCA(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]) swap(u,v);
            u=fa[top[u]];
        }
        return dep[u]<dep[v]?u:v;
    }
    T getans(int u,int v){
        int f1=top[u],f2=top[v];
        T ans=0;
        while(f1!=f2){
            if(dep[f1]<dep[f2]){
                swap(f1,f2);swap(u,v);
            }
            ans=max(ans,gao.query(1,1,pos,p[f1],p[u]));
            u=fa[f1];f1=top[u];
        }//通过重链走向LCA,不断维护操作
        if(u==v) return ans;
        if(dep[u]>dep[v]) swap(u,v);
        return max(ans,gao.query(1,1,pos,p[son[u]],p[v]));
    }
};