#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int i,n,t,cnt,a[9];
    long long int m;
    while(cin >> n >> m)
    {
        t = -11;
        cnt = 0;
        for(i = 1;i <= n;i++)
        {
            cin >> a[i];
            if(a[i] < 0)
            {
                cnt++;
                if(a[i] > t)
                    t = a[i];
            }
        }
        if(cnt % 2 == 0)
        {
            for(i = 1;i <= n;i++)
            {
                if(a[i] != 0)
                    m *= a[i];
            }
        }
        else
        {
            for(i = 1;i <= n;i++)
            {
                if(a[i] != 0 && a[i] != t)
                    m *= a[i];
            }
        }
        printf("%lld\n",m);
    }
    return 0;
}

