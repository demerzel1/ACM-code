#include <iostream>
#include <map>
using namespace std;

map<double, int> Map;

int main()
{
    double n, m, x, y;
    int num;
    while(cin >> n >> m)
    {
        cin >> num;
        Map.clear();
        for(int i=0;i<num;i++)
        {
            cin >> x >> y;
            double tmp = (x-1)*m + y;
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

