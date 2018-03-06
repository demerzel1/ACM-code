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

priority_queue <int,vector<int>,greater<int> > friends;
int self[100050];

int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        while(friends.size())
            friends.pop();
        int num;
        int minum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&num);
            friends.push(num);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&self[i]);
        }
        sort(self,self+n);
        int temp1,temp2;
        for(int i=0;i<n;i++)
        {
            temp1=abs(friends.top()-self[i]);
            friends.pop();
            temp2=abs(friends.top()-self[i]);
            while(temp1>temp2)
            {
                temp1=abs(friends.top()-self[i]);
                friends.pop();
                temp2=abs(friends.top()-self[i]);
            }
            minum+=temp1;
        }
        printf("%d\n",minum);
    }
    return 0;
}

