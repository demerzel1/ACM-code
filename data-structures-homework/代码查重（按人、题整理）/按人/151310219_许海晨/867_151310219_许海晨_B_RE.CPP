#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN=1010;

struct edge
{
    int from,to,cost;
};

class Batman
{
private:
    vector<edge> G[MAXN];
    long long limt_money;
    int num_n;
    int value[MAXN];
    int canget[MAXN];
    bool visited[MAXN];
public:
    void init()
    {
        for(int i=0;i<MAXN;i++)
            G[i].clear();
        memset(visited,0,sizeof(visited));
        memset(canget,0,sizeof(canget));
    }
    void read(int n,int m,int l)
    {
        num_n=n;
        limt_money=l;
        int v,u,c;
        edge e;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&v,&u,&c);
            e.from=v;e.to=u;e.cost=c;
            G[v].push_back(e);
            e.from=u;e.to=v;e.cost=c;
            G[u].push_back(e);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&value[i]);
        }
    }

    void dfs(int v,long long money,int &k)
    {
        canget[k++]=v;
        visited[v]=true;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(money>=e.cost&&!visited[e.to])
            {
                dfs(e.to,money-e.cost,k);
                visited[e.to]=false;
            }
        }
    }
    void compute()
    {
        int k=0;
        dfs(1,limt_money,k);
        int mm=0;
        for(int i=0;i<k;i++)
        {
            if(mm<value[canget[i]])
                mm=value[canget[i]];
        }
        printf("%d\n",mm);
    }
};
int main()
{
    int n,m;
    long long l;
    Batman bt;
    while(scanf("%d%d%lld",&n,&m,&l)!=EOF)
    {
        bt.init();
        bt.read(n,m,l);
        bt.compute();
    }
    return 0;
}

