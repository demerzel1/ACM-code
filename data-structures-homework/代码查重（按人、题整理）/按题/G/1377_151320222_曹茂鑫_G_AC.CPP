#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool g[110][110];
bool flag,visit[110];
int match[110];
int p,n;
bool dfs(int u)
{
    for(int i=1;i<=n;++i)
    {
        if(g[u][i]&&!visit[i])
        {
            visit[i]=true;
            if(match[i]==-1||dfs(match[i]))
               {
                   match[i]=u;
                return true;
               }
        }
    }
    return false;
}

int hu()
{
    int ans = 0,i;
    for(i=1;i<=p;i++)
    {
        memset(visit,false,sizeof(visit));
        if(dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    int t,x,y;
    while(scanf("%d%d",&p,&n)!=EOF)
    {
    memset(g,false,sizeof(g));
    memset(match,-1,sizeof(match));
    cin>>t;
    while(t--)
    {
    cin>>x>>y;
    g[x][y]=true;
    }
    cout<<hu()<<endl;
    }
    return 0;
}

