#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, tmp;
    vector<int> fushu;
    while(cin >> n >> m)
    {
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            if(tmp>0) m *= tmp;
            if(tmp == 0) continue;
            if(tmp<0)
            {
                fushu.push_back(tmp);
                m = m*(-tmp);
            }
        }
        if(fushu.size()%2 == 0)
            cout << m << endl;
        else
        {
            sort(fushu.begin(), fushu.end());
            m = m/(-fushu[0]);
            cout << m << endl;
        }
    }
    return 0;
}

