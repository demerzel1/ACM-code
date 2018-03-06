#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#define Max_Value 1000000
using namespace std;
int n,m;
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>n>>m)
    {
        int a[10];
        long long sum[10]={0};
        memset(sum,0,sizeof(sum));
        sum[0]=m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]*a[i];
        sort(a,a+m);
        cout<<sum[n]<<endl;
    }
}

