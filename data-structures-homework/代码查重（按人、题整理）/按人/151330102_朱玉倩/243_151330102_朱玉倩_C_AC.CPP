#include <bits/stdc++.h>

using namespace std;
struct coord
{
    int x,y;
    coord(int a,int b){x=a;y=b;}
    coord(){}
    friend bool operator < (const coord &a,const coord& b)
    {
        if(a.x==b.x)
            return a.y<b.y;
        else
            return a.x<b.x;
    }
};
map<coord,int> history;

int main()
{
    int m,n,q,x,y;
    while(cin>>n>>m)
    {
        history.clear();
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>x>>y;
            coord a = coord(x,y);
            if(history.find(a)==history.end()&&x>0&&x<=n&&y>0&&y<=m)
            {
                history[a]++;
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
    }
}
