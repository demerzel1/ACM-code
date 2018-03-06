#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct edge
{
    int u,v,w;
    int id;
    edge(int a,int b,int c,int i){u=a;v=b;w=c;id=i;}
    friend bool operator < (const edge& a,const edge& b)
    {
        return a.w<b.w;
    }
};
int n,m;
class UnionFind
{
public:
    vector<int>parent;
    int num;
    int findfather(int k);
    void uniontwo(int r1,int r2){parent[r1]=r2;}
    void initial(int n);
    void process (int x,int y);
    bool allconnect();
    bool connect(int x,int y){
        int rx= findfather(x);
        int ry = findfather(y);
        return rx==ry;
    }
};
int UnionFind::findfather(int k)
{
    if(parent[k]==k)
        return k;
    parent[k] = findfather((parent[k]));
    return parent[k];
}
void UnionFind::initial(int n)
{
    parent.clear();
    num=n;
    for(int i=0;i<=num;i++)
        parent.push_back(i);
}
void UnionFind::process(int x,int y)
{
    int rx = findfather(x);
    int ry = findfather(y);
    if(rx!=ry)
        uniontwo(rx,ry);
}
bool UnionFind::allconnect()
{
    int p =0;
    for(int i=1;i<=num;i++)
    {
        if(parent[i]==i)
            p++;
        if(p>=2)
            return false;
    }
    return true;
}
vector<edge>Edge;
vector<edge>Edge2;
vector<edge>ce;
UnionFind uf;
int kruscal1()
{
    int ans = 0;
    uf.initial(n);
    sort(Edge.begin(),Edge.end());
    for(int i=0; i<Edge.size(); i++)
    {
        int a = Edge[i].u;
        int b = Edge[i].v;
        if(!uf.connect(a,b))
        {
            uf.process(a,b);
            ans+=Edge[i].w;
        }
        if(uf.allconnect())
            return ans;

    }
    return 0;
}
int kruscal2()
{
    int ans = 0;
    uf.initial(n);
    sort(Edge2.begin(),Edge2.end());
    for(int i=0;i<Edge2.size();i++)
    {
        int a = Edge2[i].u;
        int b = Edge2[i].v;
        if(!uf.connect(a,b))
        {
            uf.process(a,b);
            ans+=Edge2[i].w;
        }
        if(uf.allconnect())
            return ans;
    }
    return 0;
}

int main()
{
    int a,b,c;
    while(cin>>n>>m)
    {
        uf.initial(n);
        Edge2.clear();
        Edge.clear();
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            Edge.push_back(edge(a,b,c,i+1));
        }
        ce.clear();
        for(int i=0;i<Edge.size();i++)
            ce.push_back(Edge[i]);
        int num = kruscal1();

        for(int i=0; i<n-1; i++)
        {
            cin>>a;
            Edge2.push_back(ce[a-1]);
        }
        int sum = kruscal2();
        if(sum==num)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

