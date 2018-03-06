#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <cstring>
#include <cmath>
using namespace std;
map<int,vector<int> >p;
int n;
int main()
{
    int t;
    long long sum;
     while(~scanf("%d",&n))
     {
         priority_queue<int, vector<int> ,greater<int>  >q;
         for(int i=0;i<n;i++)
         {
             scanf("%d",&t);
             q.push(t);
         }
         sum=0;
         int a,b;
         while(q.size()>1)
         {
             a=q.top();
             q.pop();
             b=q.top();
             q.pop();
             t=a+b;
             sum+=t;
             q.push(t);
         }
         printf("%lld\n",sum);

     }

    return 0;
}

