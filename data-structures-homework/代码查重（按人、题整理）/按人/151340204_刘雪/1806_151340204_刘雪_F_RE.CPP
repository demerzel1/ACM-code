#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

struct Edge
{
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
struct cmp
{
    bool operator () (Edge a,Edge b)
    {
        return a.w>b.w;
    }
};
class UnionFind
{
private:
    vector<int>parent;
    vector<bool>root;
public:
    void initial(int);
    int findfather(int);
    void union1(int,int);
    bool judge(int);
};
void UnionFind::initial(int n)
{
    parent.clear();
    parent.resize(n+1);
    root.clear();
    root.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        root[i]=true;
    }
}
int UnionFind::findfather(int k)
{
    int r=k;
    while(!root[r])
        r=parent[r];
    int pe,e=k;
    while(e!=r)
    {
        pe=parent[e];
        parent[e]=r;
        e=pe;
    }
    return r;
}
void UnionFind::union1(int r1,int r2)
{
    if(r1<r2)
    {
        parent[r2]=r1;
        root[r2]=false;
    }
    else
    {
        parent[r1]=r2;
        root[r1]=false;
    }
}
bool UnionFind::judge(int n)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(root[i])
            cnt++;
        if(cnt>=2)
            return false;
    }
    return true;
}
class MSTset
{
private:
    vector<int>node;
    priority_queue<Edge,vector<Edge>,cmp>edge;
    UnionFind uf;
    int sum;
    void Krusal(int);
public:
    void initial(int);
    void readCase();
    void computing(int);
};
void MSTset::initial(int n)
{
    node.clear();
    while(!edge.empty())
        edge.pop();
}
void MSTset::readCase()
{
    int m;
    scanf("%d",&m);
    node.resize(m+7);
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        edge.push(Edge(u,v,w));
        node[i]=w;
    }
}
void MSTset::Krusal(int n)
{
   int t=edge.size();
   for(int i=0;i<t;i++)
   {
       Edge e=edge.top();
       edge.pop();
       int x=uf.findfather(e.u);
       int y=uf.findfather(e.v);
       if(x!=y)
       {
           uf.union1(x,y);
           sum+=e.w;

       }
       if(uf.judge(n))
        break;
   }
}
void MSTset::computing(int n)
{
    Krusal(n);
    int r=0,x;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&x);
        r+=node[x];
    }
    if(r>sum)
        printf("NO\n");
    else
        printf("YES\n");
}
int main()
{
    MSTset mst;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        mst.initial(n);
        mst.readCase();
        mst.computing(n);
    }
    return 0;
}

