#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

class dxy
{
public:

    int x;
    int y;
    dxy(int x=0,int y=0):x(x),y(y)
    {

    }
};

bool operator <(const dxy &a,const dxy &b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

map<dxy, int >chessboard;
map<dxy, int >::iterator it;
int main()
{
    int n,m,q;
    while(cin>>n>>m>>q)
    {
        int x,y;
        while(q--)
        {
            scanf("%d%d",&x,&y);
            it=chessboard.find(dxy(x,y));
            if(it!=chessboard.end())
            {
                printf("NO\n");
            }
            else
            {
                 printf("YES\n");
                 chessboard[dxy(x,y)]=1;
            }
               
        }
    }
    return 0;
}

