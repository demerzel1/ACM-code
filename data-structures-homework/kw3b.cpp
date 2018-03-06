#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
long long  a[M];
int has[M];

int main()
{
    int n,m;
    long long sum=0,ans=0;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        if (i>1)
            ans+=(a[i]*a[i-1]);
        sum+=a[i];
    }
    ans+=a[1]*a[n];
    memset(has,0,sizeof(has));
    long long cas=0;
    while (m--)
    {
        int x,l,r;
        scanf("%d",&x);
        has[x]=1;
        if (x==1)
            l=n;
        else
            l=x-1;
        if(x==n)
            r=1;
        else
            r=x+1;
        ans+=(sum-a[x]-a[l]-a[r])*a[x];
        long long already=cas;
        if (has[l])
            already-=a[l];
        if (has[r])
            already-=a[r];
        ans-=already*a[x];
        cas+=a[x];
    }
    printf("%I64d",ans);
    return 0;
}
