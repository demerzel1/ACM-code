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
            if (a>=1)
            {
                money*=a;
            }
            if (a<0) count++;
            v.push_back(a);
        }
    }
    void computing()
    {
        sort(v.begin(),v.end());
        if (count%2)
        {
            for (int i=0;i<count-1;i++)
            {
                money*=v[i];
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

