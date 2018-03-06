#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class Bipartite
{
private:
    vector<vector<int> >right;
    vector<int>left;
    vector<bool>visited;
public:
    void initial(int,int);
    bool can(int);
    void connect(int,int);
    int calculate(int);
};
void Bipartite::initial(int n,int m)
{
    right.clear();
    right.resize(n+1);
    left.clear();
    left.resize(m+1);
    fill(left.begin(),left.end(),-1);
    visited.clear();
    visited.resize(m+1);
}
void Bipartite::connect(int x,int y)
{
    right[x].push_back(y);
}
bool Bipartite::can(int k)
{
    for(int i=0;i<right[k].size();i++)
    {
        int t=right[k][i];
        if(!visited[t])
        {
            visited[t]=true;
            if(left[t]==-1||can(left[t]))
            {
                left[t]=k;
                return true;
            }
        }
    }
    return false;
}
int Bipartite::calculate(int n)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        fill(visited.begin(),visited.end(),false);
        if(can(i))
            cnt++;
    }
    return cnt;
}
class HappyNewYear
{
private:
    Bipartite bp;
    int ans;
public:
    void initial(int,int);
    void readCase();
    void computing(int);
    void outResult();
};
void HappyNewYear::initial(int n,int m)
{
    bp.initial(n,m);
    ans=0;
}
void HappyNewYear::readCase()
{
    int k;
    scanf("%d",&k);
    int x,y;
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        bp.connect(x,y);
    }
}
void HappyNewYear::computing(int n)
{
    ans=bp.calculate(n);
}
void HappyNewYear::outResult()
{
    printf("%d\n",ans);
}
int main()
{
    HappyNewYear hny;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        hny.initial(n,m);
        hny.readCase();
        hny.computing(n);
        hny.outResult();
    }
    return 0;
}

