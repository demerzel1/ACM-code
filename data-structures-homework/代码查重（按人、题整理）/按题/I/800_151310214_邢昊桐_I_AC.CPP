#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <hash_map>
#define MAXN 1005
using namespace std;
int n;
int a[MAXN];
int sum;
int main()
{
    while(cin>>n)
    {
        int a1;sum=0;
        priority_queue<int , vector<int> , greater<int> >q;
        for(int i=1;i<=n;i++)
        {
            cin>>a1;
            q.push(a1);
        }
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            sum+=a+b;
            q.push(a+b);
        }
        cout<<sum<<endl;
    }


    return 0;
}

