#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
    bool operator() (int a, int b)
    {
        return a>b;
    }
};

int main()
{
    int n, ans;
    priority_queue<int, vector<int>, cmp> q;
    while(cin >> n)
    {
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }
        while(q.size()!=1)
        {
            int a=q.top();
            q.pop();
            int b = q.top();
            q.pop();
            ans += a+b;
            q.push(a+b);
        }
        q.pop();
        cout << ans << endl;
    }
    return 0;
}

