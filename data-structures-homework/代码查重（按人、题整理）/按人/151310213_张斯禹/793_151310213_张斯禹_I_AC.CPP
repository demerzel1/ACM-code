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
#include <set>

using namespace std;

int main()
{
    int n,m,num;
    while(scanf("%d",&n)!=EOF)
    {
        priority_queue <int,vector<int>,greater<int> > qu;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            qu.push(num);
        }
        int ans=0,num1,num2;
        while(qu.size()>1)
        {
            num1=qu.top();
            qu.pop();
            num2=qu.top();
            qu.pop();
            ans+=(num1+num2);
            qu.push(num1+num2);
        }
        printf("%d\n",ans);
    }
    return 0;
}

