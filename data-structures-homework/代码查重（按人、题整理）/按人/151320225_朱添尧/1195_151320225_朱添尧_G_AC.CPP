#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class HappyNewYear
{
private:
    int count;
    int girl;
    vector <bool> visit;
    vector <vector <int> > relation;
    vector <int> boyfriend;
    bool ask(int b)
    {
        for (int i=0;i<relation[b].size();i++)
        {
            int g=relation[b][i];
            if (!visit[g])
            {
                visit[g]=true;
                if (boyfriend[g]==-1||ask(boyfriend[g]))
                {
                    boyfriend[g]=b;
                    return true;
                }
            }
        }
        return false;
    }
public:
    void initial(int b,int g)
    {
        count=0;
        girl=g;
        visit.clear();;
        boyfriend.clear();
        relation.clear();
        relation.resize(b+1);
        boyfriend.resize(g+1,-1);
        visit.resize(g+1,false);
    }
    void readCase()
    {
        int n,b,g;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&b,&g);
            relation[b].push_back(g);
        }
    }
    void computing()
    {
        for (int i=1;i<relation.size();i++)
        {
            visit.clear();
            visit.resize(girl+1,false);
            if (ask(i)) count++;
        }
    }
    void outResult()
    {
        printf("%d\n",count);
    }
};

int main()
{
    int b,g;
    HappyNewYear hny;
    while (scanf("%d%d",&b,&g)!=-1)
    {
        hny.initial(b,g);
        hny.readCase();
        hny.computing();
        hny.outResult();
    }
    return 0;
}

