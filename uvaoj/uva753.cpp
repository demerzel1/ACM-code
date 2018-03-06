#include<bits/stdc++.h>
using namespace std;
#define INF 1e8
map<string,int> mp1;
map<string,int> mp2;
#define max_nodes 500
#define maxn 505
struct Edge {
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};
int source;         // Դ��
int sink;           // ���
int n,m,k;
struct isap {
    int num_nodes;
    int num_edges;
    vector<Edge> edges;
    vector<int> G[max_nodes]; // ÿ���ڵ�����ı߱��


    int p[max_nodes];   // ������·�ϵ���һ�����ı��
    int num[max_nodes]; // �� t ����̾������ i �Ľڵ�����
    int cur[max_nodes]; // ��ǰ���±�
    int d[max_nodes];   // ���������нڵ� i ����� t ����̾���
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
// Ԥ����, ���� BFS ���� d ����
    bool bfs() {
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

// ����
    int augment() {
        int u = sink, df = INF;
        // �ӻ�㵽Դ��ͨ�� p ׷������·��, df Ϊһ·����С�Ĳ���
        while(u != source) {
            Edge &e = edges[p[u]];
            df = min(df, e.cap - e.flow);
            u = edges[p[u]].from;
        }
        u = sink;
        // �ӻ�㵽Դ���������
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
        for(int i = 0; i < num_nodes; i++) num[d[i]]++;
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
                if(--num[d[u]] == 0) break;  // gap �Ż�
                num[d[u] = m+1]++;
                cur[u] = 0;
                if(u != source)
                    u = edges[p[u]].from;
            }
        }
        return flow;
    }
};

struct device{
    string s1;
    string s2;
}d[maxn];
struct adapter{
    string s1;
    string s2;
}a[maxn];
struct receptacle{
    string s;
}r[maxn];

int main(){
    int T;
    cin>>T;
    while(T--){
        struct isap is;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>r[i].s;
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>d[i].s1>>d[i].s2;
        cin>>k;
        for(int i=1;i<=k;i++)
            cin>>a[i].s1>>a[i].s2;
        int tn=n+m+k;
        is.init(tn+2,0,tn+1);
        for(int i=1;i<=m;i++){
            is.AddEdge(0,i,1);
            for(int j=1;j<=k;j++)
                if(d[i].s2==a[j].s1)
                    is.AddEdge(i,j+m,INF);

            for(int j=1;j<=n;j++){
                if(d[i].s2==r[j].s)
                    is.AddEdge(i,m+k+j,1);
            }
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                if(i!=j&&a[i].s2==a[j].s1)
                    is.AddEdge(i+m,j+m,INF);
            }
            for(int j=1;j<=n;j++){
                if(a[i].s2==r[j].s)
                    is.AddEdge(i+m,m+k+j,INF);
            }
        }
        for(int i=1;i<=n;i++){
            is.AddEdge(m+k+i,tn+1,1);
        }
        cout<<m-is.max_flow()<<"\n";
        if(T!=0)
            cout<<"\n";
    }
    return 0;
}



