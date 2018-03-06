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
int a[100];
long long Max;
long long play(int index,int flag,long long money)
{
    if(flag==0||index>n)
        return money;
    long long m1=play(index+1,1,money*a[index]);
    long long m2=play(index+1,0,money);
    return m1>m2?m1:m2;
}
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            cin>>a[i];
        Max=play(1,1,m);
        cout<<(Max>m?Max:m)<<endl;
    }
}

