#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct cmp
{
    bool operator() (const int& a,const int& b)
    {
        return a>b;
    }
};
priority_queue<int,vector<int>,cmp>pq;
int main()
{
    int n,a;
    while(cin>>n)
    {
        int sum = 0;
        while(!pq.empty())
            pq.pop();
        for(int i=0; i<n; i++)
        {
            cin>>a;
            pq.push(a);
        }
        if(n<=1)
        {
            while(!pq.empty())
            {
                sum+=pq.top();
                pq.pop();
            }
        }
        else
        {
            while(pq.size()>1)
            {
                int t1 = pq.top();
                pq.pop();
                int t2 = pq.top();
                pq.pop();
                sum = sum+t1+t2;
                pq.push(t1+t2);
            }
        }
        cout<<sum<<endl;
    }
}



