#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

struct Edge
{
    int u,v;
    int weight;
    int id;
    Edge (int uu=0,int vv=0,int w=0,int idd=0)
    {
        u=uu;
        v=vv;
        weight=w;
        id=idd;
    }
    friend bool operator < (Edge a1,Edge a2)
    {
        return a1.weight>a2.weight;
    }
};

class UnionFind
{
private:
    vector <int> parent;
    vector <bool> root;
public:
    void initial(int size)
    {
        parent.clear();
        root.clear();
        parent.resize(size+1,1);
        root.resize(size+1,true);
    }
    int find (int k)
    {
        int r=k;
        while(!root[r])
        {
            r=parent[r];
        }
        int e=k;
        int pe;
        while(e!=r)
        {
            pe=parent[e];
            parent[e]=r;
            e=pe;
        }
        return r;
    }
    void union1(int r1,int r2)
    {
        if (parent[r1]>parent[r2])
        {
            parent[r1]+=parent[r2];
            parent[r2]=r1;
            root[r2]=false;
        }
        else
        {
            parent[r2]+=parent[r1];
            parent[r1]=r2;
            root[r1]=false;
        }
    }
};

class MSTest
{
private:
    int nodenum;
    int edgenum;
    UnionFind uf;
    vector <bool> ans;
    priority_queue <Edge> q;
    vector <int> ask;
public:
    void initial(int n,int e)
    {
        ans.clear();
        while(!q.empty())
        {
            q.pop();
        }
        ans.resize(e+1,false);
        uf.initial(n);
        nodenum=n;
        edgenum=e;
        ask.clear();
    }
    void readCase()
    {
        int u,v,w,a;
        for (int i=1;i<=edgenum;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            q.push(Edge(u,v,w,i));
        }
        for (int i=0;i<nodenum-1;i++)
        {
            scanf("%d",&a);
            ask.push_back(a);
        }
    }
    void computing()
    {
        Edge term;
        int r1,r2;
        while (!q.empty())
        {
            term=q.top();
            q.pop();
            r1=uf.find(term.u);
            r2=uf.find(term.v);
            if (r1!=r2)
            {
                uf.union1(r1,r2);
                ans[term.id]=true;
            }
        }
    }
    void outResult()
    {
        for (int i=0;i<ask.size();i++)
        {
            if (ans[ask[i]]==false)
            {
                printf("NO\n");
                break;
            }
        }
        printf("YES\n");
    }
};

int main()
{
   int n,e;
   MSTest mst;
   while (scanf("%d%d",&n,&e)!=-1)
   {
        mst.initial(n,e);
        mst.readCase();
        mst.computing();
        mst.outResult();
   }
    return 0;
}

