#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

struct cmp
{
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};
class NewtonandApple
{
private:
    priority_queue<int,vector<int>,cmp>qu;
    int ans;
public:
    void initial();
    void readCase(int);
    void computing();
    void outResult();
};
void NewtonandApple::initial()
{
    while(!qu.empty())
        qu.pop();
    ans=0;
}
void NewtonandApple::readCase(int n)
{
    int x;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        qu.push(x);
    }
}
void NewtonandApple::computing()
{
    int result;
    while(qu.size()>1)
    {
        int m=qu.top();
        qu.pop();
        int n=qu.top();
        qu.pop();
        result=m+n;
        qu.push(result);
        ans+=result;
    }
}
void NewtonandApple::outResult()
{
    printf("%d\n",ans);
}
int main()
{
    NewtonandApple na;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        na.initial();
        na.readCase(n);
        na.computing();
        na.outResult();
    }
    return 0;
}

