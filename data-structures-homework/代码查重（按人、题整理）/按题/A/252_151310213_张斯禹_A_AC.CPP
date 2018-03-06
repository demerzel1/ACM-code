#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <sstream>

using namespace std;

int maxmoney;
int m,n;
int multi[10];
int played;

void dfs(int now,int money,int depth)
{
    if(depth==n)
    {
        if(money>maxmoney)
            maxmoney=money;
        return;
    }
    dfs(now+1,money*multi[now],depth+1);
    dfs(now+1,money,depth+1);
}

int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            cin>>multi[i];
        maxmoney=0;
        dfs(0,m,0);
        cout<<maxmoney<<endl;
    }
    return 0;
}

