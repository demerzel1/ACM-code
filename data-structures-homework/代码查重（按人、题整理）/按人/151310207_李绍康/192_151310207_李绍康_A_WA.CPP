#include <iostream>

using namespace std;

int main()
{
    int i,n,m,t,cnt,a[9];
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
        cout << m << endl;
    }
    return 0;
}

