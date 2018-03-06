#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define max 1000005
using namespace std;

int main()
{  int n,m;
   long long sum=0;
   priority_queue<int,vector<int>,greater<int> >use;
    while(scanf("%d",&n)!=EOF)
    { sum=0;
      for(int i=0;i<n;i++)
      {
          scanf("%d",&m);
          use.push(m);
      }
      while(use.size()>1){

        int a=use.top();use.pop();
        int b=use.top();use.pop();
        sum=sum+a+b;
        use.push(a+b);
      }
      printf("%lld\n",sum);
      while(use.size()) use.pop();
    }
    return 0;
}

