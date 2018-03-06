#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int u[1000005],v[1000005];
int n,m;
int a,b;
int x;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        scanf("%d",&x);
        for(int i=1;i<=x;i++)
        {
            scanf("%d%d",&a,&b);
            if(u[a]==0&&v[b]==0)
            {
                cout<<"YES"<<endl;
                u[a]=1;
                v[b]=1;
            }
            else
                cout<<"NO"<<endl;
        }
    }

    return 0;
}

