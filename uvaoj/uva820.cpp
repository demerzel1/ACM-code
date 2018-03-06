#include<bits/stdc++.h>
using namespace std;
#define maxn 105
struct Edge {
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};

struct EdmondsKarp {
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int p[maxn];

    void init(int n) {
        for(int i=0; i<=n; i++)
            G[i].clear();
        edges.clear();
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
    }

    void AddEdge(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int Maxflow(int s,int t){
        int flow=0;
        while(true){
            memset(a,0,sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s]=INT_MAX;
            while(!Q.empty()){
                int x=Q.front();
                Q.pop();
                for(int i=0;i<G[x].size();i++){
                    Edge& e=edges[G[x][i]];
                    if(!a[e.to]&&e.cap>e.flow){
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t])
                    break;
            }
            if(!a[t])
                break;
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};


int main(){
    int n;
    int s,t,c;
    int cas=0;
    struct EdmondsKarp ek;
    while(scanf("%d",&n)!=EOF&&n){
        cas++;
        ek.init(n+1);
        scanf("%d%d%d",&s,&t,&c);
        int x,y,z;
        for(int i=0;i<c;i++){
            scanf("%d%d%d",&x,&y,&z);
            ek.AddEdge(x,y,z);
            ek.AddEdge(y,x,z);
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",cas,ek.Maxflow(s,t));
    }
    return 0;
}
