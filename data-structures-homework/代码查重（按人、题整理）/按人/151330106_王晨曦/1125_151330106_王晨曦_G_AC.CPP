#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int >maps[102];
int flag[102];
int link[102];

void initial(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        maps[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
        link[i]=-1;
    }

}

int dfs(int n)
{
    for(int i=0;i<maps[n].size();i++)
    { 
        int v=maps[n][i];
        if(!flag[v])
        {
            flag[v]=1;
            //cout<<"v"<<v<<" "<<"link[v]"<<link[v]<<" "<<endl;;
            if(link[v]==-1||dfs(link[v]))
            {
                link[v]=n;
                return 1;
            }

        }
    }
    return 0;
}

void solve(int n,int m)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(dfs(i))
        {
            sum++;
        }
    }
    cout<<sum<<endl;
}

int main()
{
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        initial(n,m);
        int x,y;
        while(k--)
        {
            cin>>x>>y;
            maps[x].push_back(y);
        }

        solve(n,m);
    }
    return 0;
}

