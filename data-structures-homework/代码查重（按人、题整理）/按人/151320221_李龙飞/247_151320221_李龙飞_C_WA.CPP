#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<long long, int> Map;

int main()
{
    int n, m, num, x, y;
    while(cin >> n >> m)
    {
        cin >> num;
        Map.clear();
        for(int i=0;i<num;i++)
        {
            cin >> x >> y;
            long long tmp = (x-1)*1000000 + y;
            if(x<=n && y<=m && x>=1 && y>=1)
            {
                if(Map[tmp] == 0)
                {
                    cout << "YES" << endl;
                    Map[tmp] = 1;
                }
                else
                    cout << "NO" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

