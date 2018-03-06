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

int friends[100050];
int self[100050];

int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int num;
        int minum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&friends[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&self[i]);
        }
        sort(self,self+n);
        sort(friends,friends+m);
        int temp1,temp2;
        int i,flag=0,tot=0;
        for(i=0;m-i<n-tot;i++)
        {
            temp1=abs(friends[tot]-self[i]);
            tot++;
            temp2=abs(friends[tot]-self[i]);
            while(temp1>temp2)
            {
                temp1=abs(friends[tot]-self[i]);
                tot++;
                temp2=abs(friends[tot]-self[i]);
            }
            minum+=temp1;
        }
        for(;i<n;i++)
        {
            minum+=abs(friends[tot]-self[i]);
            tot++;
        }
        printf("%d\n",minum);
    }
    return 0;
}

