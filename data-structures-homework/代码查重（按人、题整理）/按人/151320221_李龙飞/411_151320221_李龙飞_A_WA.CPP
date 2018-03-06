#include <iostream>
using namespace std;

int main()
{
    int n, m, a[10];
    while(cin >> n >> m)
    {
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
        {
            if(a[i] > 0) m *= a[i];
            else if(a[i] == 0) continue;
            else
            {
                if(a[i+1]<0) m = m*a[i]*a[i+1];
                i++;
            }
        }
        cout << m << endl;
    }
    return 0;
}

