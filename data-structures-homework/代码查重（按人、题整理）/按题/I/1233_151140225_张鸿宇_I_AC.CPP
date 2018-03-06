#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        int sum = 0;
        priority_queue<int, vector<int>, greater<int> > que;
        for(int i = 0; i < n; ++i)
        {
            int t;
            cin >> t;
            que.push(t);
        }
        while(true)
        {
            int a = que.top();
            que.pop();
            int b = que.top();
            que.pop();
            sum = sum + a + b;
            que.push(a+b);
            if(que.size() == 1)
            {
                cout << sum << endl;break;
            }
        }
    }
    return 0;
}

