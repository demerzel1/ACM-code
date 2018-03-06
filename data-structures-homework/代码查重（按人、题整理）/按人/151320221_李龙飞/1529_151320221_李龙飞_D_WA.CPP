#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, tmp;
    vector<int> a;
    while(cin >> n >> m)
    {
        long long ans = 0;
        a.clear();
        for(int i=0;i<m;i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end());
        for(int i=0;i<n;i++)
        {
            cin >> tmp;
            vector<int>::iterator it = lower_bound(a.begin(), a.end(), tmp);
            if(it == a.begin())
                ans += a[it-a.begin()] - tmp;
            else
            {
                int x = a[it-a.begin()];
                int y = a[it-a.begin()-1];
                ans += min(x-tmp, tmp-y);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

