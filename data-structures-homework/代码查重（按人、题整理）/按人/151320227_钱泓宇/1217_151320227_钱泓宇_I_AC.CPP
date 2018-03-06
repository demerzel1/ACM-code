#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n,t,a,b;
int main()
{
    long long int sum;
    while(~scanf("%d",&n))
    {
         priority_queue<int,vector<int>,greater<int> >q;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            q.push(t);
        }
        sum=0;
        if(q.size()==1)
        {
            a=q.top();
            sum+=a;
            q.pop();
        }
        while(q.size()>1)
        {
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            t=a+b;
            sum+=t;
            q.push(t);
        }
        printf("%lld\n",sum);
    }
    return 0;
}

