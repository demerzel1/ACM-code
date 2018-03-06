#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
long long int e[1010][1010];
long long int dis[1010];
int book[1010];
long long int h[1010];
long long int INF=99999999;
long long int n,m,q;
long long int i,j;
long long int u,v,c;
long long int Min,ans;
int main()
{
   while(scanf("%lld%lld%lld",&n,&m,&q)!=EOF)
   {
     for(i=1;i<n;i++)
        for(j=1;j<=n;j++)
        if(i==j) e[i][j]=0;
     else e[i][j]=INF;

     for(i=1;i<=m;i++)
     {
         scanf("%lld%lld%lld",&u,&v,&c);
         e[u][v]=c;
     }

     for(i=1;i<=n;i++)
     {
         scanf("%lld",&h[i]);
     }

     for(i=1;i<=n;i++)
        dis[i]=e[1][i];

     for(i=1;i<=n;i++)
        book[i]=0;
     book[1]=1;

     for(i=i;i<=n-1;i++)
     {
         Min=INF;
         for(j=1;j<=n;j++)
         {
             if(book[j]==0&&dis[j]<Min)
             {
                 Min=dis[j];
                 u=j;
             }
         }
         book[u]=1;
         for(v=1;v<=n;v++)
         {
             if(e[u][v]<INF)
             {
                 if(dis[v]>dis[u]+e[u][v])
                    dis[v]=dis[u]+e[u][v];
             }
         }
     }
     ans=0;
     for(i=1;i<=n;i++)
     {
         if(dis[i]<=q)
         {
             if(h[i]>ans)
                ans=h[i];
         }
     }
     printf("%lld\n",ans);
   }
   return 0;
}

