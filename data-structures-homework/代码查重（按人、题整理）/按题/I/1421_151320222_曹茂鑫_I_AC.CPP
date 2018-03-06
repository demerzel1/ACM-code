#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct cmp
{
    bool operator()(int a,int b)
    {
    return a>b;
    }
};

priority_queue<int,vector<int>,cmp>q;

int main()
{
    int t,a,b,m,sum,i;
    while(scanf("%d",&m)!=EOF)
    {
    sum=0;
    for(i=0;i<m;i++)
    {
    cin>>t;
    q.push(t);
    }
    while(q.size()!=1)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        sum=sum+a+b;
        q.push(a+b);
    }
    cout<<sum<<endl;
    while(!q.empty())
    {
        q.pop();
    }
    }
    return 0;
}

