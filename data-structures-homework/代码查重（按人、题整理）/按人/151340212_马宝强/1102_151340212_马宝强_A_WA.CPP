#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#define Max_Value 1000000
using namespace std;
long long  n,m;
int a[100];
long long Max;
long long play(int index,int flag,long long money)
{
    if(flag==0)
        return money;
    if(index==n)
    	return money*a[index];
    int t1=play(index+1,1,money*a[index]);
    int t2=play(index+1,0,money);
    return t1>t2?t1:t2;
}
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>n>>m)
    {
        Max=0;

        for(int i=1;i<=n;i++)
            cin>>a[i];
        Max=play(1,1,m);
        cout<<(Max>m?Max:m)<<"\n";
    }
}

