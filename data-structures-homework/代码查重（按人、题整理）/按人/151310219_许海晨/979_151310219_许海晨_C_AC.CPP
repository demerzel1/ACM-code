#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <list>

using namespace std;

struct node
{
    int x,y;
};
bool operator <(node a,node b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    else
        return a.y<b.y;
}
class Kiki
{
private:
    map<node,int> m1;
public:
    void init()
    {
        m1.clear();
    }
    void read(int n,int m)
    {
        int q,x,y;
        scanf("%d",&q);
        node p;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            p.x=x;p.y=y;
            m1[p]++;
            if(m1[p]>1)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
};
int main()
{
    int n,m;
    Kiki kk;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        kk.init();
        kk.read(n,m);
    }
    return 0;
}

