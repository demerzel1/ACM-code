#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const long long INF=20000005;

const int maxsize=1005;

class BatmanTrouble
{
private:
    int edgenum;
    int nodenum;
    long long money;
    long long node[maxsize];
    long long cost[maxsize];
    bool used[maxsize];
    static long long relation[maxsize][maxsize];
    void dijkstra(int s)
    {
        cost[s]=0;
        while(true)
        {
            int v=-1;
            for (int u=1;u<=nodenum;u++)
            {
                if (!used[u]&&(v==-1||cost[u]<cost[v])) v=u;
            }
            if (v==-1) break;
            used[v]=true;
            for (int u=1;u<=nodenum;u++)
            {
                cost[u]=min(cost[u],cost[v]+relation[v][u]);
            }
        }
    }
public:
    void initial(long long n,long long m,long long l)
    {
        edgenum=m;
        nodenum=n;
        money=l;
        memset(relation,INF,sizeof(relation));
        memset(cost,INF,sizeof(cost));
        memset(used,false,sizeof(used));
    }
    void readCase()
    {
        int u,v;
        long long c;
        for (int i=0;i<edgenum;i++)
        {
            scanf("%d%d%lld",&u,&v,&c);
            relation[u][v]=c;
            relation[v][u]=c;
        }
        for (int i=1;i<=nodenum;i++)
        {
            scanf("%lld",&c);
            node[i]=c;
        }
    }
    void computing()
    {
        dijkstra(1);
    }
    void outResult()
    {
        long long m=0;
        for (int i=1;i<nodenum;i++)
        {
            if (cost[i]<=money)
            {
                m=max(node[i],m);
            }
        }
        printf("%lld\n",m);
    }
};

long long BatmanTrouble::relation[maxsize][maxsize];

int main()
{
    long long n,m,l;
    BatmanTrouble bt;
    while(scanf("%lld%lld%lld",&n,&m,&l)!=-1)
    {
        bt.initial(n,m,l);
        bt.readCase();
        bt.computing();
        bt.outResult();
    }
    return 0;
}

