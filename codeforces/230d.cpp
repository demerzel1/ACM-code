#include<bits/stdc++.h>
using namespace std;
#define MAX_V 100005
#define INF 0x7fffffff
typedef pair<int,int> P;

struct edge {
    int to;
    int cost;
    edge(int a,int b) {
        to=a;
        cost=b;
    }
};
int n,m;
vector<int> arrive[MAX_V];
bool vis[MAX_V];
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    memset(vis,0,sizeof(vis));
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V+1,INF);
    d[s]=0;
    //  for(int i=0;i<arrive[1].size();i++){
    //if(d[1]==arrive[1][i]){
    //  printf("d[1]=%d arrive=%d\n",d[1],arrive[1][i]);
    //             d[1]++;
    //        }
    // }
    // printf("d1=%d\n",d[1]);
    que.push(P(d[1],s));
    while(!que.empty()) {
        //    cout<<111<<endl;
        P p=que.top();
        que.pop();
        int v=p.second;
        if(vis[v]) continue;
        vis[v]=1;
        if(v==n)
            break;
        for(int j=0; j<arrive[v].size(); j++) {
            if(d[v]==arrive[v][j]) {
                d[v]++;
            }
            if(d[v]<arrive[v][j])
                break;

        }
        for(int i=0; i<G[v].size(); i++) {
            edge e=G[v][i];
            //   printf("v=%d\n",v);
            bool flag=false;
            //    int addnum=0;
            // if(e.to!=n)

            //   printf("d[v]=%d addnum=%d\n",d[v],addnum);
            //    printf("e.to=%d d[e.to]=%d d[v]+e.cost+addnum=%d\n",e.to,d[e.to],d[v]+e.cost+addnum);
            if(d[e.to]>d[v]+e.cost) {

                //          cout<<222<<endl;
                if(d[e.to]=d[v]+e.cost);
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d%d",&n,&m);
    V=n;
    for(int i=1; i<=m; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(edge(b,c));
        G[b].push_back(edge(a,c));
    }
    for(int i=1; i<=n; i++) {
        int num;
        scanf("%d",&num);
        for(int j=0; j<num; j++) {
            int a;
            scanf("%d",&a);
            arrive[i].push_back(a);
        }
    }
    dijkstra(1);
    if(d[n]==INF) {
        printf("-1\n");
    } else
        printf("%d\n",d[n]);
    return 0;
}
