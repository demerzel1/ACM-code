#include<bits/stdc++.h>
using namespace std;

#define INF 1e6
#define max_nodes 50

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
        memset(d,-1,sizeof(d));
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
        for(int i = 0; i < num_nodes; i++){
            if(d[i]==-1)
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
    string s;
    while(getline(cin,s)){
        int n=38;
        struct isap is;
        is.init(38,36,37);
        int sum=0;
        while(!s.empty()){
            sum=sum+s[1]-'0';
            for(int i=0;i<s[1]-'0';i++)
                is.AddEdge(36,s[0]-'A'+10,1);
            int sz=s.size();
            for(int i=3;i<sz-1;i++)
                is.AddEdge(s[0]-'A'+10,s[i]-'0',1);
            getline(cin,s);
        }
        for(int i=0;i<10;i++)
            is.AddEdge(i,37,1);
        int ans=is.max_flow();
        if(ans==sum){
            for(int i=0;i<10;i++){
                if(is.G[i].size()>1){
                  //  printf("sz=%d\n",is.G[i].size());
                    int j;
                    for(j=0;j<is.G[i].size();j++){
                        int v=is.G[i][j];
                       // printf("v=%d is.edges[v].flow=%d\n",v,is.edges[v].flow);
                        if(is.edges[v].flow==-1&&is.edges[v].to!=37){
                            printf("%c",is.edges[v].to+'A'-10);
                            break;
                        }
                    }
                    if(j==is.G[i].size())
                        printf("_");
                }else
                    printf("_");
            }
            printf("\n");
        }else{
            cout<<"!\n";
        }
    }
    return 0;
}



