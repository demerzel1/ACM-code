#include<bits/stdc++.h>
using namespace std;

#define INF 1000000
#define max_nodes 5005

int dx[]= {-1,1,0,0};
int dy[]= {0,0,1,-1};


struct Edge {
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};
int source;         // 源点
int sink;           // 汇点
struct isap {
    int num_nodes;
    int num_edges;
    vector<Edge> edges;
    vector<int> G[max_nodes]; // 每个节点出发的边编号


    int p[max_nodes];   // 可增广路上的上一条弧的编号
    int num[max_nodes]; // 和 t 的最短距离等于 i 的节点数量
    int cur[max_nodes]; // 当前弧下标
    int d[max_nodes];   // 残量网络中节点 i 到汇点 t 的最短距离
    bool visited[max_nodes];

    void init(int n,int s,int t) {
        source=s;
        sink=t;
        num_nodes=n;
        num_edges=0;
        for(int i=0; i<=n; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int cap) {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
        num_edges+=2;
    }
// 预处理, 反向 BFS 构造 d 数组
    bool bfs() {
        fill(d,d+max_nodes,INT_MAX);
        memset(visited, 0, sizeof(visited));
        queue<int> Q;
        Q.push(sink);
        visited[sink] = 1;
        d[sink] = 0;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(auto ix = G[u].begin(); ix != G[u].end(); ++ix) {
                Edge &e = edges[(*ix)^1];
                if(!visited[e.from] && e.cap > e.flow) {
                    visited[e.from] = true;
                    d[e.from] = d[u] + 1;
//                    printf("e.from=%d u=%d d[u]=%d\n",e.from,u,d[u]);
                    Q.push(e.from);
                }
            }
        }
        return visited[source];
    }

// 增广
    int augment() {
        int u = sink, df = INF;
        // 从汇点到源点通过 p 追踪增广路径, df 为一路上最小的残量
        while(u != source) {
            Edge &e = edges[p[u]];
            df = min(df, e.cap - e.flow);
            u = edges[p[u]].from;
        }
        u = sink;
        // 从汇点到源点更新流量
        while(u != source) {
            edges[p[u]].flow += df;
            edges[p[u]^1].flow -= df;
            u = edges[p[u]].from;
        }
        return df;
    }
    int max_flow() {
        int flow = 0;
        bfs();
        memset(num, 0, sizeof(num));
        for(int i = 0; i < num_nodes; i++) {
//            printf("i=%d d[i]=%d\n",i,d[i]);
            if(d[i]==INT_MAX)
                continue;
            num[d[i]]++;
        }
        int u = source;
        memset(cur, 0, sizeof(cur));
        while(d[source] < num_nodes) {
            if(u == sink) {
                flow += augment();
                u = source;
            }
            bool advanced = false;
            for(int i = cur[u]; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if(e.cap > e.flow && d[u] == d[e.to] + 1) {
                    advanced = true;
                    p[e.to] = G[u][i];
                    cur[u] = i;
                    u = e.to;
                    break;
                }
            }
            if(!advanced) {  // retreat
                int m = num_nodes - 1;
                for(auto ix = G[u].begin(); ix != G[u].end(); ++ix)
                    if(edges[*ix].cap > edges[*ix].flow)
                        m = min(m, d[edges[*ix].to]);
                if(--num[d[u]] == 0) break;  // gap 优化
                num[d[u] = m+1]++;
                cur[u] = 0;
                if(u != source)
                    u = edges[p[u]].from;
            }
        }
        return flow;
    }
};

int X,Y,P;
int mp[35][35];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    while(cin>>X>>Y>>P) {
        memset(mp,0,sizeof(mp));
        string s;
        for(int i=1; i<=X; i++) {
            cin>>s;
            for(int j=0; j<Y; j++) {
                if(s[j]=='*') {
                    mp[i][j+1]=1;
                }
                if(s[j]=='~') {
                    mp[i][j+1]=0;
                }
                if(s[j]=='.') {
                    mp[i][j+1]=2;
                }
                if(s[j]=='@') {
                    mp[i][j+1]=3;
                }
                if(s[j]=='#') {
                    mp[i][j+1]=4;
                }
            }
        }
        int cnt=X*Y*2+2;
//        cout<<cnt<<" cnt\n";
        struct isap is;
        is.init(cnt,0,X*Y*2+1);
        for(int i=1; i<=X; i++) {
            for(int j=1; j<=Y; j++) {
//                cout<<mp[i][j]<<" ";
                int u=(i-1)*Y+j;
                int v=u+X*Y;
                if(mp[i][j]==1) {
                    is.AddEdge(u,v,1);
                    is.AddEdge(0,u,1);
                    for(int k=0; k<4; k++) {
                        int tx=i+dx[k];
                        int ty=j+dy[k];
                        if(tx>=1&&tx<=X&&ty>=1&&ty<=Y) {
                            int tu=(tx-1)*Y+ty;
                            int tv=tu+X*Y;
                            if(mp[tx][ty]==2)
                                is.AddEdge(v,tu,1);
                            if(mp[tx][ty]==3||mp[tx][ty]==4)
                                is.AddEdge(v,tu,1);
                        }
                    }
                }
                if(mp[i][j]==2) {
                    is.AddEdge(u,v,1);
                    for(int k=0; k<4; k++) {
                        int tx=i+dx[k];
                        int ty=j+dy[k];
                        if(tx>=1&&tx<=X&&ty>=1&&ty<=Y) {
                            int tu=(tx-1)*Y+ty;
                            int tv=tu+X*Y;
                            if(mp[tx][ty]==2)
                                is.AddEdge(v,tu,1);
                            if(mp[tx][ty]==3||mp[tx][ty]==4)
                                is.AddEdge(v,tu,1);
                        }
                    }
                }
                if(mp[i][j]==3) {
                    is.AddEdge(u,v,INF);
                    for(int k=0; k<4; k++) {
                        int tx=i+dx[k];
                        int ty=j+dy[k];
                        if(tx>=1&&tx<=X&&ty>=1&&ty<=Y) {
                            int tu=(tx-1)*Y+ty;
                            int tv=tu+X*Y;
                            if(mp[tx][ty]==2)
                                is.AddEdge(v,tu,INF);
                            if(mp[tx][ty]==3||mp[tx][ty]==4)
                                is.AddEdge(v,tu,INF);
                        }
                    }
                }
                if(mp[i][j]==4) {
                    is.AddEdge(u,v,INF);
                    is.AddEdge(v,2*X*Y+1,P);
                    for(int k=0; k<4; k++) {
                        int tx=i+dx[k];
                        int ty=j+dy[k];
                        if(tx>=1&&tx<=X&&ty>=1&&ty<=Y) {
                            int tu=(tx-1)*Y+ty;
                            int tv=tu+X*Y;
                            if(mp[tx][ty]==2)
                                is.AddEdge(v,tu,INF);
                            if(mp[tx][ty]==3||mp[tx][ty]==4)
                                is.AddEdge(v,tu,INF);
                        }
                    }
                }
            }
//            cout<<"\n";
        }
        cout<<is.max_flow()<<"\n";
    }
    return 0;
}



