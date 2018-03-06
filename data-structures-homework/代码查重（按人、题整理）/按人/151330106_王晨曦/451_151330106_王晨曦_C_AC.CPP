#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

class dxy
{
public:

    long long int x;
    long long int y;
    dxy(long long int x=0,long long int y=0):x(x),y(y)
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
    long long int n,m,q;
    while(cin>>n>>m>>q)
    {
        chessboard.clear();
        long long int x,y;
        while(q--)
        {
            scanf("%lld%lld",&x,&y);
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

