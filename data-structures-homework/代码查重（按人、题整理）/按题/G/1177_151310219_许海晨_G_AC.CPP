#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN=205;

class Happy
{
private:
    int num_v;
    vector<int>G[MAXN];
    int match[MAXN];
    bool used[MAXN];
    int num_n;
public:
    void init()
    {
        for(int i=0;i<MAXN;i++)
            G[i].clear();
    }
    void read(int n,int m,int k)
    {
        num_v=m+n;
        num_n=n;
        int v,u;
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&v,&u);
            u=u+num_n;
            G[v].push_back(u);
            G[u].push_back(v);
        }
    }
    bool dfs(int v)
    {
        used[v]=true;
        for(int i=0;i<G[v].size();i++)
        {
            int u=G[v][i];
            int w=match[u];
            if(w<0||!used[w]&&dfs(w))
            {
                match[v]=u;
                match[u]=v;
                return true;
            }
        }
        return false;
    }
    void compute()
    {
        int res=0;
        memset(match,-1,sizeof(match));
        for(int v=1;v<=num_n;v++)
        {
            if(match[v]<0)
            {
                memset(used,0,sizeof(used));
                if(dfs(v))
                    res++;
            }
        }
        cout<<res<<endl;
    }
};
int main()
{
    int n,m,k;
    Happy ha;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d",&k);
        ha.init();
        ha.read(n,m,k);
        ha.compute();
    }
    return 0;
}

