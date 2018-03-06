#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <hash_map>
#define MAXN 1005
using namespace std;

int N,M;
int K;
int mat[101][101];
int vis[101];
int link[101];
int num;
int can(int t)
{
    for(int i=1;i<=M;i++)
    {
        if(vis[i]==0 && mat[t][i])
        {
            vis[i]=1;
            if(link[i]==0 || can(link[i]))
            {
                link[i]=t;
                return 1;
            }
        }
    }
    return 0;
}
void findmax()
{
    memset(link,0,sizeof(link));
    num=0;
    for(int i=1;i<=N;i++)
    {
        memset(vis,0,sizeof(vis));
        if(can(i)==1) num++;
    }
}
int main()
{
    while(cin>>N>>M)
    {
        cin>>K;
        memset(mat,0,sizeof(mat));
        for(int i=0;i<K;i++)
        {
            int a,b;
            cin>>a>>b;
            mat[a][b]=1;
        }
        findmax();
        cout<<num<<endl;
    }


    return 0;
}

