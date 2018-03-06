#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
   bool operator ()  (int a,int b)
   {
       return a>b;
   }
};
priority_queue<int,vector<int>,cmp> S;
int n;
int main()
{
     int i;
     int temp;
     while(scanf("%d",&n)!=EOF)
     {
         for(i=1;i<=n;i++)
         {
             scanf("%d",&temp);
             S.push(temp);
         }
         long long sum=0;
         int t;
         while(S.size()>1)
         {
             t=S.top();
             S.pop();
             t+=S.top();
             S.pop();
             sum+=t;
             S.push(t);
         }
         printf("%lld\n",sum);
         while(!S.empty())
            S.pop();
     }
    return 0;
}

