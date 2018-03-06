#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class InterestingGame
{
private:
    vector <int> v;
    int money;
    int gamenum;
    int count;
public:
    void initial(int n,int m)
    {
        count=0;
        v.clear();
        gamenum=n;
        money=m;
    }
    void readCase()
    {
        int a;
        for (int i=0;i<gamenum;i++)
        {
            scanf("%d",&a);
            if (a>=1||a<0)
            v.push_back(a);
            if (a<0) count++;
        }
    }
    void computing()
    {
        int pr;
        sort(v.begin(),v.end());
        for (int i=0;i<v.size();i++)
        {
            pr=money;
            if (v[i]<0)
            {
                money*=v[i]*v[i+1];
            }
            else
            {
                money*=v[i];
            }
            if (money<0||money<pr)
            {
                money=pr;
            }
        }
    }
    void outResult()
    {
        printf("%d\n",money);
    }
};

int main()
{
    int n,m;
    InterestingGame ig;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        ig.initial(n,m);
        ig.readCase();
        ig.computing();
        ig.outResult();
    }
    return 0;
}

