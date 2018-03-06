#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n,m,k=0;
    int num[20];
    long long sum;
   while(scanf("%d%d",&n,&m)!=EOF)
   {  k=0;
      sum=m;
      for(int i=0;i<n;i++)
      {
          scanf("%d",&num[i]);
          if(num[i]<0) k++;
      }
      sort(num,num+n);
      for(int i=0;i<n;i++)
      {
          if(num[i]!=0)
          {
              if(k%2!=0&&num[i]<0&&num[i+1]>=0);
              else sum=sum*num[i];
          }
      }
      printf("%lld\n",sum);
   }
    return 0;
}

