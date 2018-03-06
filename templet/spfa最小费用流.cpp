#include <bits/stdc++.h>
using namespace std;
 
const double INF=1e18;
const double eps=1e-6;
const int MAXN=505;
typedef pair<int,int> ii;
struct mcmf{
    double mincost,flow;
    struct edge{
        int to,rev;
        double cost,cap;
        edge(){};
        edge(int a,double b,double c,int d):to(a),cap(b),cost(c),rev(d){};
    };
    vector<edge>gra[MAXN];
    double dist[MAXN];
    double aug[MAXN];
    bool in[MAXN];
    ii prev[MAXN];
 
    void init(int n){for(int i=0;i<n;i++){gra[i].clear();}}
 
    void addedge(int from,int to,double cap,double cost){
        gra[from].emplace_back(edge(to,cap,cost,(int)gra[to].size()));
        gra[to].emplace_back(edge(from,0,-cost,(int)gra[from].size()-1));
    }
    void mcmf_spfa(int S,int T){
        flow=mincost=0;
        for(;;){
            int u,v;queue<int>Q;
            fill(dist,dist+MAXN,INF);dist[S]=0;
            memset(in,0,sizeof in); in[S]=1;
            Q.push(S); aug[S]=INF;
            while(!Q.empty()){
                u=Q.front();Q.pop();in[u]=0;
                for(int i=0;i<gra[u].size();i++){
                    edge &e=gra[u][i]; v=e.to;
                    if(e.cap>0&&dist[v]>dist[u]+e.cost+eps){
                        dist[v]=dist[u]+e.cost;
                        prev[v]=ii(u,i);
                        aug[v] = min(aug[u], e.cap);
                        if(!in[v]){ in[v]=1; Q.push(v);}
                    }
                }
            }
            if(dist[T]>=INF) return;
            mincost+=1.0*dist[T]*aug[T];
            flow+=aug[T];
            for(v=T;v!=S;v=prev[v].first){
                edge &e=gra[prev[v].first][prev[v].second];
                e.cap-=aug[T];
                gra[v][e.rev].cap+=aug[T];
            }
        }
    }
}solve;
 
int n,m;
 
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int st=502,ed=503;
        cin>>n>>m;
        solve.init(MAXN);
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            solve.addedge(st,i,a,0);
            solve.addedge(i,ed,b,0);
        }
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            double p;
            cin>>a>>b>>c>>p;
            if(c!=0){
                solve.addedge(a,b,1,0);
                solve.addedge(a,b,c-1,-log(1-p));
            }
        }
        solve.mcmf_spfa(st,ed);
        double tmp=-solve.mincost;
        //cout<<-tmp<<endl;
        double ans=exp(tmp);
        printf("%.2f\n",1-ans);
        //cout<<1-ans<<'\n';
    }
    return 0;
}