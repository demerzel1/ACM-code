#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;
struct Num
{
    int a;
    friend bool operator < (Num a1,Num a2)
    {
        return a1.a>a2.a;
    }
    Num(int aa=0)
    {
        a=aa;
    }
};

class NewtonandApple
{
private:
    priority_queue <Num> q;
    int num;
    int ans;
public:
    void initial(int n)
    {
        num=n;
        while (!q.empty())
        {
            q.pop();
        }
        ans=0;
    }
    void readCase()
    {
        int a;
        for (int i=0;i<num;i++)
        {
            scanf("%d",&a);
            q.push(Num(a));
        }
    }
    void computing()
    {
        int term;
        while(q.size()>1)
        {
            term=q.top().a;
            q.pop();
            term+=q.top().a;
            q.pop();
            q.push(term);
            ans+=term;
        }
    }
    void outResult()
    {
        printf("%d\n",ans);
    }
};

int main()
{
    int n;
    NewtonandApple na;
    while (scanf("%d",&n)!=-1)
    {
        na.initial(n);
        na.readCase();
        na.computing();
        na.outResult();
    }
    return 0;
}

