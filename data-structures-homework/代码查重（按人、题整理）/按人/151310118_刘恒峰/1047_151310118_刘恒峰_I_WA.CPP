#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>

using namespace std;

priority_queue<int ,vector<int>,greater<int> >que;
int a;
int main()
{
    int n;
    while (cin>>n)
    {
        long long int total=0;
        long long int cnt=0;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            que.push(a);
        }
        total+=que.top();
        que.pop();
        total+=que.top();
        que.pop();
        cnt=total;
        while (!que.empty())
        {
            cnt+=que.top();
            total+=cnt;
            que.pop();
        }
        cout<<total<<endl;

    }
    return 0;
}

