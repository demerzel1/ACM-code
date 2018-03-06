#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int T[10];
int main()
{
    int sum;
    int temp=-20;
    int c;
    int i=0;
    int f;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        temp=-20;
        f=0;
        sum=m;
       for(i=1;i<=n;i++)
       {
           scanf("%d",&T[i]);
           if(T[i]<0)
           {
               f++;
               if(temp<T[i])
               {
                   temp=T[i];
                   c=i;
               }
           }
       }
       bool flag=false;
       if(f%2)
       {
           flag=true;
       }
       for(i=1;i<=n;i++)
       {
           if(flag&&i==c)
             continue;
           if(T[i!=0])
            sum*=T[i];
       }

        printf("%d\n",sum);
    }

    return 0;
}


