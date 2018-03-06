#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long int i,n,m,t,cnt,flag,a[9];
    while(cin >> n >> m)
    {
        t = -11;
        cnt = 0;
        flag = 0;
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
                if(a[i] != 0 && flag == 1)
                    m *= a[i];
                if(a[i] == t && flag == 0)
                    flag = 1;
            }
        }
        printf("%lld\n",m);
    }
    return 0;
}

