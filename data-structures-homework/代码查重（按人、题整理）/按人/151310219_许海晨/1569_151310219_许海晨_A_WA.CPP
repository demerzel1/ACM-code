#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n,m;
    long long ans[11],a[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans[0]=m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            ans[i+1]=ans[i]*a[i];
        }
        long long mm=0;
        for(int i=0;i<=n;i++)
        {
            if(mm<ans[i])
                mm=ans[i];
        }
        cout<<mm<<endl;
    }
    return 0;
}
