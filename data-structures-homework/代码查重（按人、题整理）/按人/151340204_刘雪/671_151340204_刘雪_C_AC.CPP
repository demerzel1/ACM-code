#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<int,int>pa;
class Game
{
private:
    map<pa,int>node;
public:
    void initial();
    void readCase();
};
void Game::initial()
{
    node.clear();
}
void Game::readCase()
{
    int t;
    scanf("%d",&t);
    int x,y;
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&x,&y);
        if(node[pa(x,y)]==0)
        {
            node[pa(x,y)]++;
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}
int main()
{
    Game g;
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        g.initial();
        g.readCase();
    }
    return 0;
}

