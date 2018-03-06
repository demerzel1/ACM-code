#include <iostream>

using namespace std;

int main()
{
    int i,n,m,t,cnt,a[9];
    while(cin >> n >> m)
    {
        cnt = 0;
        for(i = 1;i <= n;i++)
        {
            cin >> a[i];
            if(a[i] < 0)
            {
                cnt++;
                if(cnt == 2)
                {
                    cnt = 0;
                    m = m * t * a[i];
                }
                else
                    t = a[i];
            }
            else
            {
                if(a[i] != 0)
                    m *= a[i];
            }
        }
        cout << m << endl;
    }
    return 0;
}

