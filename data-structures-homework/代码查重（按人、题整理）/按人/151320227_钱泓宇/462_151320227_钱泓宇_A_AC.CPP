#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[10];
int b[10];
int main()
{
    int n,m;
    int ans;
    while(cin>>n>>m)
    {
      for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
     ans=m;
     for(int i=1;i<=n;i++)
     {
        if(a[i]!=0)
        ans= ans*a[i];
     }
     if(ans>0)
        cout<<ans<<endl;
     else{
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0)
            {
               b[cnt]=a[i];
               cnt++;
            }
        }
         int mi=-20;
         for(int i=0;i<cnt;i++)
         {
             if(b[i]>mi)
                mi=b[i];
         }
         ans=ans/mi;
         cout<<ans<<endl;

     }

    }
   return 0;
}

