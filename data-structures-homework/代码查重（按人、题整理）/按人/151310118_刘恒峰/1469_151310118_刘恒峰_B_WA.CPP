#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>


using namespace std;
int maps[1005][1005];
bool sign[1005];
struct place
{
    long long int cost;
    int val;
    int no;
    void init()
    {
        cost=0;
        val=0;
    }
}crime[500000];


int n,m;
long long int l;
queue<place> route;

void bfs()
{
    place temp=route.front();
    sign[temp.no]=true;
    for (int i=temp.no,j=1;j<=n;j++)
    {
        if (maps[i][j] && !sign[j])
        {
            crime[j].cost=maps[i][j]+temp.cost;
            route.push(crime[j]);
        }
    }
    route.pop();
}

int main()
{
    while (cin>>n>>m>>l)
    {
        for (int i=1;i<=n;i++)
        {
            crime[i].init();
            crime[i].no=i;
        }
        int x,y,c;
        memset(maps,0,sizeof(maps));
        memset(sign,0,sizeof(sign));
        for (int i=0;i<m;i++)
        {
            cin>>x>>y>>c;
            if (!maps[x][y])
            {
                maps[x][y]=c;
                maps[y][x]=c;
            }
            else if (c<maps[x][y])
            {
                maps[x][y]=c;
                maps[y][x]=c;
            }
        }
        for (int i=1;i<=n;i++)
        {
            cin>>crime[i].val;
        }
        crime[1].cost=0;
        route.push(crime[1]);
        while (!route.empty())
        {
            bfs();
        }
        int des=1,maxval=crime[1].val;
        for (int i=2;i<=n;i++)
        {
            if (sign[i])
            {
                if (crime[i].cost<=l && crime[i].val>maxval)
                {
                    des=i;
                    maxval=crime[i].val;
                }
            }
        }
        cout<<maxval<<endl;
    }
    return 0;
}

