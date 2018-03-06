#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    vector<int>a;
    priority_queue<int>b;
    int n,m;
    while(cin>>n>>m)
    {
        a.clear();
        int ax;
        for(int i=0;i<n;i++)
        {
            cin>>ax;
            if(ax>0)
                a.push_back(ax);
            if(ax<0)
                b.push(-ax);
        }
        if(b.size()%2==1)
            b.pop();
        long long int sum=m;
        for(int i=0;i<a.size();i++)
        {
            sum=sum*a[i];
        }
        while(!b.empty())
        {
            sum=sum*b.top();
            b.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}

