#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m)
    {
        int res = m;
        vector<int> d;
        vector<int> fu;
        int s = 0;
        for(int i = 0; i < n; ++i)
        {
            int t;
            cin >> t;
            if(t == 0) continue;
            d.push_back(t);
            if(t < 0) fu.push_back(t);
        }
        for(int i = 0; i < d.size(); ++i) res = res*d[i];
        if(fu.size() % 2 == 0)
        {
            cout << res << endl;
        }
        else
        {
            int t = *max_element(fu.begin(), fu.end());
            cout << res/t << endl;
        }

    }
    return 0;
}

