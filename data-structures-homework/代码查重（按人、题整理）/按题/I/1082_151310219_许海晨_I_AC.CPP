#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class Newton
{
private:
    priority_queue <int,vector<int>,greater<int> > que;
    int ans;
    int num_n;
public:
    void init()
    {
        while(!que.empty())
            que.pop();
        ans=0;
    }
    void read(int n)
    {
        int a;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            que.push(a);
        }
        while(que.size()>1)
        {
            int l1,l2;
            l1=que.top();
            que.pop();
            l2=que.top();
            que.pop();
            ans+=l1+l2;
            que.push(l1+l2);
        }
        printf("%d\n",ans);
    }
};
int main()
{
    int n;
    Newton ne;
    while(scanf("%d",&n)!=EOF)
    {
        ne.init();
        ne.read(n);
    }
    return 0;
}
