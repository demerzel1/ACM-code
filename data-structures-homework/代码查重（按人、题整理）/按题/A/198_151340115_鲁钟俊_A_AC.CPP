#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <cstring>
#include <queue>
#include <sstream>


bool cmp(int a,int b)
{
    return a>b;
}

using namespace std;

int main()
{
    long long ans;
    int x,n,m,i;
    int a[15],b[15];
    while(cin>>n>>m)
    {
        int t1=0;
        int t2=0;
        memset(a,0,sizeof(a));
        memset(a,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            cin>>x;
            if(x>0)  a[t1++]=x;
            else if(x<0)  b[t2++]=x*(-1);
        }
        if(t1>0)
        {
            for(i=0;i<t1;i++)
            {
                m*=a[i];
            }
        }
        sort(b,b+t2,cmp);
        if(t2>=2)
        {
            if(t2%2==1)
            {
            for(i=0;i<t2-1;i++)
            {
                m*=b[i];
            }

            }
            else
            {
                for(i=0;i<t2;i++)
            {
                m*=b[i];
            }
            }
        }
        ans=m;
        cout<<ans<<endl;
    }
    return 0;
}

