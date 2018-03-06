#define INF 1e6
#define max_nodes 500

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
    void AddEdge(int from,int to,int cap){
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





