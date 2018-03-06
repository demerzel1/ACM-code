#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxsize=400000;

class SegmentTree
{
private:
    static long long node[maxsize];
    static long long lazy[maxsize];
    void PushUp(int rt)
    {
        node[rt]=node[rt<<1]+node[rt<<1|1];
    }
    void PushDown(int rt,int m)
    {
        if (lazy[rt])
        {
            lazy[rt<<1]+=lazy[rt];
            lazy[rt<<1|1]+=lazy[rt];
            node[rt<<1]+=lazy[rt]*(m-(m>>1));
            node[rt<<1|1]+=lazy[rt]*(m>>1);
            lazy[rt]=0;
        }
    }
public:
    void build (int l,int r,int rt)
    {
        memset(node,0,sizeof(node));
        memset(lazy,0,sizeof(lazy));
    }
    void update(int l,int r,int ul,int ur,int value,int rt)
    {
        if (ul<=l&&r<=ur)
        {
            lazy[rt]+=value;
            node[rt]+=value*(r-l+1);
        }
        else
        {
            PushDown(rt,r-l+1);
            int m=(l+r)>>1;
            if (ul<=m)
            {
                update(l,m,ul,ur,value,rt<<1);
            }
            if (ur>m)
            {
                update(m+1,r,ul,ur,value,rt<<1|1);
            }
            PushUp(rt);
        }
    }
    long long query (int l,int r,int ql,int qr,int rt)
    {
        if (ql<=l&&r<=qr)
        {
            return node[rt];
        }
        else
        {
            PushDown(rt,r-l+1);
            int m=(l+r)>>1;
            long long c=0;
            if (ql<=m)
            {
                c+=query(l,m,ql,qr,rt<<1);
            }
            if (qr>m)
            {
                c+=query(m+1,r,ql,qr,rt<<1|1);
            }
            return c;
        }
    }
};

long long SegmentTree::node[maxsize];
long long SegmentTree::lazy[maxsize];

class WantTicket
{
private:
    SegmentTree st;
    int stations;
    int seats;
    int passengers;
public:
    void initial(int n,int s,int p)
    {
        st.build(1,stations,1);
        stations=n;
        seats=s;
        passengers=p;
    }
    void process()
    {
        int a,b;
        for (int i=0;i<passengers;i++)
        {
            scanf("%d%d",&a,&b);
            if (st.query(1,stations,a,b-1,1)<seats)
            {
                printf("Yes\n");
                st.update(1,stations,a,b-1,1,1);
            }
            else
            {
                printf("No\n");
            }
        }
    }
};

int main()
{
    int n,s,p;
    WantTicket wt;
    while (scanf("%d%d%d",&n,&s,&p)!=-1)
    {
        wt.initial(n,s,p);
        wt.process();
    }
    return 0;
}

