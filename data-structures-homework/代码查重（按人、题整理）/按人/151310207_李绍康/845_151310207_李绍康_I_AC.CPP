#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int c,d,i,n,m,ans;
    priority_queue<int,vector<int>,greater<int> > a;
    while(cin >> n)
    {
        while(!a.empty())
            a.pop();
        ans = 0;
        for(i = 0;i < n;i++)
        {
            cin >> m;
            a.push(m);
        }
        while(a.size() != 1)
        {
            c = a.top();
            a.pop();
            d = a.top();
            a.pop();
            ans += (c + d);
            a.push(c + d);
        }
        cout << ans << endl;
    }
    return 0;
}

