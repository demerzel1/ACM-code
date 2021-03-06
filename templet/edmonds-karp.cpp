#include<bits/stdc++.h>
#define maxn 10005
struct Edge {
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};

struct EdmondsKarp {
    int n,m;
    vector<Edge> edges;//边数的两倍
    vector<int> G[maxn];
    int a[maxn];//起点到i时的可改进量
    int p[maxn];//最短路树上p的入弧编号
    int s;
    int t;

    void init(int n,int ss,int tt) {
        for(int i=0; i<n; i++)
            G[i].clear();
        edges.clear();
        s=ss;
        t=tt;
    }

    void AddEdge(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int Maxflow(){
        int flow=0;
        while(true){
            memset(a,-1,sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s]=INF;
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
                edges[p[u]^1],flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};

