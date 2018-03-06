//Code here
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int a[10];
int main()
{
    int n,m;
    int f,l;
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
        ans= ans*a[i];
     }
     if(ans>=0)
        cout<<ans<<endl;
     else{
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0)
            {
                f=i;
                break;
            }

        }
        for(int i=n;i>=1;i--)
        {
            if(a[i]<0)
            {
                l=i;
                break;
            }
        }
        int ans1=ans/a[f];
        int ans2=ans/a[l];
        if(ans1>ans2)
            ans=ans1;
        else
            ans=ans2;
        cout<<ans<<endl;
     }

    }
   return 0;
}

