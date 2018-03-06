#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;


int main()
{
    int n,m,a[20],fushu,f[20];
    int ans;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=m;
        fushu=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
            {
                f[fushu]=a[i];
                fushu++;
            }
        }
        if(fushu%2==0)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==0)
                    continue;
                ans=ans*a[i];
            }
        }
        else
        {
            int mm=-999;
            for(int i=0;i<fushu;i++)
            {
                if(f[i]>mm)
                    mm=f[i];
            }
            for(int i=0;i<n;i++)
            {
                if(a[i]==mm||a[i]==0)
                    continue;
                ans=ans*a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


