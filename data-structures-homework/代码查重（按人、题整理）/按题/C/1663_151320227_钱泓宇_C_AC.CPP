#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int u[1000005],v[1000005],w[1000005],f[1000005],n[1000005];
int N,M;
int a,b;
int x;
bool Find(int s,int e)
{
    int flag=0;
    int k=f[s];
    while(k!=-1)
    {
        if(e==v[k])
        {
            flag=1;
            break;
        }
        k=n[k];
    }
    if(flag==1)
    {
        printf("NO\n");
        return false;
    }
    else
    {
        printf("YES\n");
        return true;
    }

}

int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        memset(f,-1,sizeof(f));
        memset(n,0,sizeof(n));
        scanf("%d",&x);
        for(int i=1;i<=x;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            if(Find(u[i],v[i]))
            {
            w[i]=1;
            n[i]=f[u[i]];
            f[u[i]]=i;
            }

        }
    }

    return 0;
}

