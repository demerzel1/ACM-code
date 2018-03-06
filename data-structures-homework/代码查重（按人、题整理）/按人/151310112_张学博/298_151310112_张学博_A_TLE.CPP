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
int n,m;
int main()
{
    vector<int> a;
    int x;
    while(scanf("%d%d",&n,&m))
    {
          a.clear();
          for(int i=0;i<n;i++)
          {
              scanf("%d",&x);
              if(x!=0)
              {
                  a.push_back(x);
              }
          }
          sort(a.begin(),a.end());
          int k=lower_bound(a.begin(),a.end(),0)-a.begin();
          if(k%2!=0)
          {
              for(int i=0;i<a.size();i++)
              {
                  if(i!=k)
                  m=m*a[i];
              }
          }
          else
          {
              for(int i=0;i<a.size();i++)
              {
                  m=m*a[i];
              }
          }
           printf("%d\n",m);

    }
    return 0;
}

