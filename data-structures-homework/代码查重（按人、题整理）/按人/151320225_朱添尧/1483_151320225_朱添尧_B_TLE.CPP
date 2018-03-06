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
    static long long relation[maxsize][maxsize];
public:
    void initial(long long n,long long m,long long l)
    {
        edgenum=m;
        nodenum=n;
        money=l;
        memset(relation,INF,sizeof(relation));
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
        for (int i=1;i<=nodenum;i++)
        {
            relation[i][i]=0;
        }
        for (int k=1;k<=nodenum;k++)
        {
            for (int i=1;i<=nodenum;i++)
            {
                for (int j=1;j<=nodenum;j++)
                {
                    relation[i][j]=min(relation[i][j],relation[i][k]+relation[k][j]);
                }
            }
        }
    }
    void outResult()
    {
        long long m=0;
        for (int i=1;i<nodenum;i++)
        {
            if (relation[1][i]<=money)
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

