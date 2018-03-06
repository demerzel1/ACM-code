#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class bipartieMatch
{
private:
    int girlnum,boynum;
    vector<bool>asked;
    bool hasfeeling[105][105];
    int cp[105];
public:
    void initial(int g,int b){
        memset(hasfeeling,false,sizeof(hasfeeling));
        girlnum = g;
        boynum = b;
        asked.clear();
        asked.resize(g+1);
        memset(cp,-1,sizeof(cp));
    }
    int maxMatch();
    bool can(int boy);
    void addEdge(int u,int v)
    {
        hasfeeling[u][v] = true;
    }
};
int bipartieMatch::maxMatch()
{
    int ans = 0;
    for(int i=0;i<boynum;i++)
    {
        fill(asked.begin(),asked.end(),false);
        if(can(i))
            ans++;
    }
    return ans;
}
bool bipartieMatch::can(int boy)
{
    for(int girl=0;girl<girlnum;girl++)
    {
        if(!asked[girl]&&hasfeeling[girl][boy])
        {
            asked[girl] = true;
            if(cp[girl]==-1||can(cp[girl]))
            {
                cp[girl] = boy;
                return true;
            }
        }
    }
    return false;
}
bipartieMatch bm;
int main()
{
    int n,m,k,a,b;
    while(cin>>n>>m>>k)
    {
        bm.initial(n,m);
        for(int i=0;i<k;i++)
        {
            cin>>a>>b;
            bm.addEdge(a-1,b-1);
        }
        int result = bm.maxMatch();
        cout<<result<<endl;
    }
}


