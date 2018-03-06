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
        long long ans = m;
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            if(tmp>0) ans *= tmp;
            if(tmp == 0) continue;
            if(tmp<0)
            {
                fushu.push_back(tmp);
                ans = ans*(-tmp);
            }
        }
        if(fushu.size()%2 == 0)
            cout << ans << endl;
        else
        {
            sort(fushu.begin(), fushu.end());
            ans = ans/(-fushu[fushu.size()-1]);
            cout << ans << endl;
        }
    }
    return 0;
}

