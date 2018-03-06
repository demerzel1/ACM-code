#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<stdlib.h>
using namespace std;
const int N=110000;
long long f[35];
map<long long,int>mp;
long long a[N];
int main()
{
    int n;
    int cnt=1;
    f[0]=1;
    for(int i=1;f[i]<=2*1e9+10;i++)
    {
        f[i]=f[i-1]*2;
        if(f[i]>2*1e9+10)
        break;
    }

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        mp[a[i]]++;
    }
    long long ans=0;
    for(int i=0;i<=34;i++)
    {
        for(int j=0;j<n;j++)
        {
            long long tmp=f[i]-a[j];
            if(a[j]==tmp)
            {
               ans+=mp[tmp]-1;
            }
            else
            ans+=mp[tmp];
        }
    }
    printf("%I64d\n",ans/2);
    return 0;
}
