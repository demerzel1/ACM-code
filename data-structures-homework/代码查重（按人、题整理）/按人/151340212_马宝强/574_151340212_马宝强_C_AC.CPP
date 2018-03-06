#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define Max_value 1000005
using namespace std;
int N,M,Q;
int x,y;
map < int,map<int,int> >chess;
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>N>>M>>Q)
    {
        chess.clear();
        for(int i=0;i<Q;i++)
        {
            cin>>x>>y;
            if(x<1||y<1||x>N||y>M)
            {
            	cout<<"NO\n";
            	continue;
            }
            if(chess.count(x)&&chess[x].count(y))
            {
                cout<<"NO\n";
                continue;
            }
            cout<<"YES\n";
            chess[x][y]=1;
        }
    }
    return 0;
}

