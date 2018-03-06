#include <bits/stdc++.h>
using namespace std;
typedef double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>ii;
const int MAXN=200011;
int cases;

bool in[MAXN];
template<class T>inline void read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}
struct Dsu{
    int seed[MAXN];
    Dsu(){memset(seed,-1,sizeof(seed));}
    int find(int x){return seed[x]<0?x:seed[x]=find(seed[x]);}
    bool join(int a,int b){
        a=find(a);b=find(b); if(a==b) return 0;
        if(seed[a]>seed[b]){seed[b]+=seed[a];seed[a]=b;}
        else               {seed[a]+=seed[b];seed[b]=a;}
        return 1;
    }
};
template<typename T> struct Kruskal{
    struct edge{
        int u,v,id;
        T c;
        edge(){}
        edge(int x,int y,T z):u(x),v(y),c(z){}
    };
    vector<edge>e;
    void addedge(int u,int v,T c){e.emplace_back(edge(u,v,c));}
    void id_sort(){
        sort(e.begin(),e.end(),[&](const edge&e1,const edge&e2){
            return e1.id<e2.id;
        });
    }
    T query(int n){
        Dsu dsu;int cnt=0;T tot=0;
        sort(e.begin(),e.end(),[&](const edge&e1,const edge&e2){
            return e1.c<e2.c;
        });
        for(const auto&t:e){
            if(dsu.join(t.u,t.v)){
                ++cnt;tot+=t.c;
                in[t.id]=1;
            }
            if(cnt+1==n) break;
        }
        return tot;
    }
};
template<typename T> struct Segtree{
#define ls (o<<1)
#define rs (o<<1)|1
    T lazy[MAXN<<2];
    T data[MAXN<<2];
    void pushup(int o){
        data[o]=max(data[ls],data[rs]);
    }
    void build(int o,int l,int r){
        lazy[o]=0;
        if(l==r){
            data[o]=0;
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);build(rs,mid+1,r);
        pushup(o);
    }
    void update(int o,int l,int r,int x,T v){
        if(x==l&&r==x){
            data[o]=v;
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid) update(ls,l,mid,x,v);
        if(x>mid)  update(rs,mid+1,r,x,v);
        pushup(o);
    }
    T query(int o,int l,int r,int x,int y){
        if(x<=l&&r<=y){
            return data[o];
        }
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return max(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
    }
};

template<typename T,typename C>
struct TreeDecomposition{
    T gao;
    struct e{
        int u,v;C c;
        e(){}
        e(int x,int y,C z):u(x),v(y),c(z){}
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
    void addedge(int u,int v,C c){
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
            if(dep[t.u]>dep[t.v]){
                swap(t.u,t.v);
            }
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
    C getans(int u,int v){
        int f1=top[u],f2=top[v];
        C ans=0;
        while(f1!=f2){
            if(dep[f1]<dep[f2]){
                swap(f1,f2);swap(u,v);
            }
            ans=max(ans,gao.query(1,1,pos,p[f1],p[u]));
            u=fa[f1];f1=top[u];
        }
        if(u==v) return ans;
        if(dep[u]>dep[v]) swap(u,v);
        return max(ans,gao.query(1,1,pos,p[son[u]],p[v]));
    }
};
Kruskal<ll>kruskal;
TreeDecomposition<Segtree<ll>,ll>decomp;
int main(){
    int n,m,x,y;
    ll w;
    read(n),read(m);
    if(!m) return 0;
    for(int i=0;i<m;i++){
        read(x),read(y),read(w);
        kruskal.addedge(x,y,w);
        kruskal.e.back().id=i;
    }
    auto ans=kruskal.query(n);
    for(const auto&t:kruskal.e){
        if(in[t.id]){
            decomp.addedge(t.u,t.v,t.c);
        }
    }
    kruskal.id_sort();
    decomp.solve();
    for(int i=0;i<m;i++){
        if(in[i]) printf("%lld\n",ans);
        else{
            auto o=decomp.LCA(kruskal.e[i].u, kruskal.e[i].v);
            auto d1=decomp.getans(o,kruskal.e[i].u);
            auto d2=decomp.getans(o,kruskal.e[i].v);
            printf("%lld\n",ans+kruskal.e[i].c-max(d1,d2));
        }
    }
}