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
        int ans = 0;
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
            ans += a[lower_bound(a.begin(), a.end(), tmp) - a.begin()] - tmp;
            a.erase(lower_bound(a.begin(), a.end(), tmp));
        }
        cout << ans << endl;
    }
    return 0;
}

