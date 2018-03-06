#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<double, int> Map;

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
            double tmp = ((x-1)*m + y)/10000.0;
            if(Map[tmp] == 0)
            {
                cout << "YES" << endl;
                Map[tmp] = 1;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

