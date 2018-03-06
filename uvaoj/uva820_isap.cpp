#include<bits/stdc++.h>
using namespace std;
#define max_nodes 105
struct Edge {
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};
int source;         // Դ��
int sink;           // ���
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

    void init(int n) {
        num_nodes=n-1;
        num_edges=0;
        for(int i=0; i<n; i++)
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
//                    cout<<"di= "<<e.from<<"\n";
                    d[e.from] = d[u] + 1;
                    Q.push(e.from);
                }
            }
        }
        return visited[source];
    }

// ����
    int augment() {
        int u = sink, df = INT_MAX;
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
//        cout<<111<<"\n";
        memset(num, 0, sizeof(num));
        for(int i = 0; i < num_nodes; i++){
//            cout<<d[i]<<"\n";
            num[d[i]]++;

        }
//        cout<<555<<"\n";
        int u = source;
        memset(cur, 0, sizeof(cur));

        while(d[source] < num_nodes) {
            if(u == sink) {
                flow += augment();
                u = source;
            }
//            cout<<333<<"\n";
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
//            cout<<222<<"\n";

            if(!advanced) {  // retreat
                int m = num_nodes - 1;
                for(auto ix = G[u].begin(); ix != G[u].end(); ++ix)
                    if(edges[*ix].cap> edges[*ix].flow)
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

int main(){
    int n;
    int c;
    int cas=0;
    struct isap is;
    while(scanf("%d",&n)!=EOF&&n){
        cas++;
        is.init(n+1);
        scanf("%d%d%d",&source,&sink,&c);
        source--;
        sink--;
        int x,y,z;
        for(int i=0;i<c;i++){
            scanf("%d%d%d",&x,&y,&z);
            is.AddEdge(x-1,y-1,z);
            is.AddEdge(y-1,x-1,z);
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",cas,is.max_flow());
    }
    return 0;
}
