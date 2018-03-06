#include <iostream>
#include<cstdio>
#include<queue>


using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            q.push(a);
        }
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            int c=a+b;
            sum+=c;
            q.push(c);
        }
        printf("%d\n",sum);
    }
    return 0;
}

