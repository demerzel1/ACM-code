#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m,n;
bool line[105][105],used[105];
int girl[105];
bool find(int x)
{
    int j;
    for(j=1;j<=n;j++)
    {
        if(line[x][j]==true&&used[j]==false)
        {
            used[j]=1;
            if(girl[j]==0||find(girl[j]))
            {
                girl[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int all=0;
    while(cin>>m>>n)
    {
        all=0;
        memset(line,false,sizeof(line));
        memset(girl,0,sizeof(girl));
        int x;
        cin>>x;
        while(x--)
        {
            int a,b;
            cin>>a>>b;
            line[a][b]=true;
        }
        for(int i=1;i<=m;i++)
        {
            memset(used,0,sizeof(used));
            if(find(i)) all++;
        }
        cout<<all<<endl;
    }
    return 0;
}

