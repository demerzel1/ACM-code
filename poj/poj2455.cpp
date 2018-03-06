#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <iomanip>
#include <set>
#include <complex>
#include <cstring>
#include <cstdio>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MAXN=205;
const int MAXM=40005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

struct node{
    int u;
    int v;
    int l;
    node(){}
    node(int a,int b,int c):u(a),v(b),l(c){}
}ee[MAXM];


int n,p,tt;

typedef int T;
struct Edge {
    int to,next;
    T cap;
    Edge(){}
    Edge(int a,int b,T c):to(a),next(b),cap(c){}
}edge[MAXM<<1];
int tot,head[MAXN];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,T w) {
    edge[tot]=Edge(v,head[u],w);
    head[u]=tot++;
    edge[tot]=Edge(u,head[v],w);//双向边改成w
    head[v]=tot++;
}
int dis[MAXN],cur[MAXN],gap[MAXN],pre[MAXN];
bool bfs(int s,int t){// 逆向BFS
    memset(gap,0,sizeof(gap));
    memset(dis,-1,sizeof(dis));
    queue<int>Q;int i,u,v;
    Q.push(t);dis[t]=0;
    while(!Q.empty()) {
        u=Q.front();Q.pop();
        for(i=head[u];~i;i=edge[i].next){
            v=edge[i].to;
            if(~dis[v])continue;
            dis[v]=dis[u]+1;
            gap[dis[v]]++;
            Q.push(v);
        }
    }
    return ~dis[s];
}
T isap(int n,int s,int t){//源，汇
    if(!bfs(s,t))return 0;
    int i,u=s;T ans=0;
    copy(head,head+n+1,cur);
    while(dis[s]<n){
        if(u==t){
            T aug=INF;
            for(i=s;i!=t;i=edge[cur[i]].to){
                aug=min(aug,edge[cur[i]].cap);
            }
            for(i=s;i!=t;i=edge[cur[i]].to){
                edge[cur[i]].cap-=aug;
                edge[cur[i]^1].cap+=aug;
            }
            ans+=aug;u=s;
        }
        for(i=cur[u];~i;i=edge[i].next){
            Edge &e=edge[i];
            if(e.cap>0 && dis[u]==dis[e.to]+1){
                cur[u]=i;pre[e.to]=i^1;
                u=e.to;break;
            }
        }
        if(~i)continue;
        if(--gap[dis[u]]==0)break;
        cur[u]=head[u];
        int mi=n;
        for(i=head[u];~i;i=edge[i].next){
            Edge &e=edge[i];
            if(e.cap>0 && dis[e.to]<mi){
                mi=dis[e.to];
            }
        }
        gap[dis[u]=mi+1]++;
        if(u!=s)u=edge[pre[u]].to;
    }
    return ans;
}

bool judge(int x){
    init();
    for(int i=1;i<=p;++i){
        if(ee[i].l<=x){
            addedge(ee[i].u,ee[i].v,1);
        }
    }
    int s=n+1;
    int t=n+2;
    addedge(s,1,INF);
    addedge(t,n,INF);
    int ans=isap(n+2,s,t);
   // printf("ans=%d\n",ans);
    if(ans>=tt)
        return true;
    return false;
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(~scanf("%d%d%d",&n,&p,&tt)){
        for(int i=1;i<=p;++i){
            scanf("%d%d%d",&ee[i].u,&ee[i].v,&ee[i].l);
        }
        int l=0,r=1000000;
        while(r-l>3){
            int mid=(l+r)>>1;
            if(judge(mid)){
                r=mid;
            } else
                l=mid;
        }
        int ans=l;
        for(int i=l;i<=r;++i){
            if(judge(i)){
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}