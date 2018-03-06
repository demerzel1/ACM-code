#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> S;
int n,m;
int T[10];
int main()
{
    int sum;
    int temp=0;
    int c;
    int i=0;
    int f;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        f=0;
        sum=m;
        S.push(sum);
       for(i=1;i<=n;i++)
       {

       //    cout<<sum<<endl;
           scanf("%d",&T[i]);

       }
       int j;
       for(i=1;i<=n;i++)
       {
                sum*=T[j];
              S.push(sum);
       }

        printf("%d\n",S.top());
        while(!S.empty())
        {
            S.pop();

        }
    }

    return 0;
}


