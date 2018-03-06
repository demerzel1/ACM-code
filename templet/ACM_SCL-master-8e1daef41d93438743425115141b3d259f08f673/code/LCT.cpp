#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=10000+5;
int n,m;
struct node
{
    node *f;
    node *ch[2];
    bool rev;
}tree[maxn],*null,Tnull;
void init(node *u)
{
    u->f=u->ch[0]=u->ch[1]=null;
    u->rev=0;
}
bool isroot(node *u)
{
    return u==null||u->f->ch[0]!=u&&u->f->ch[1]!=u;
}
void pushdown(node *u)
{
    if(u==null)return ;
    if(u->rev)
    {
        swap(u->ch[0],u->ch[1]);
        if(u->ch[0]!=null)u->ch[0]->rev^=1;
        if(u->ch[1]!=null)u->ch[1]->rev^=1;
        u->rev=0;
    }
}
void rotate(node *u)
{
    node *f=u->f;
    node *ff=f->f;
    int d=u==f->ch[1];

    if(u->ch[d^1]!=null)u->ch[d^1]->f=f;
    f->ch[d]=u->ch[d^1];

    u->f=ff;
    if(ff!=null)
    {
        if(f==ff->ch[0])ff->ch[0]=u;
        else if(f==ff->ch[1])ff->ch[1]=u;
    }

    u->ch[d^1]=f;
    f->f=u;
}

void clearR(node *x)
{
    if(x==null) return;
    if(x->f!=null) clearR(x->f);
    pushdown(x);
}

/*int cnt;
node *sta[maxn];*/
void splay(node *u)
{
    if(u==null)return ;
    /*cnt=1;
    sta[0]=u;
    for(node *y=u;!isroot(y);y=y->f)
    {
        sta[cnt++]=y->f;
    }
    while(cnt)pushdown(sta[--cnt]);  */
    clearR(u);
    while(!isroot(u))
    {
        node *f=u->f;
        if(isroot(f))
        {
            rotate(u);
        }
        else
        {
            node *ff=f->f;
            int d=u==f->ch[1];
            int dd=f==ff->ch[1];
            if(d==dd)rotate(f);
            else rotate(u);
            rotate(u);
        }
    }
}
node *access(node *u)
{
    node *v=null;
    while(u!=null)
    {
        splay(u);
        u->ch[1]=v;
        //v->f=u;
        v=u;
        u=u->f;
    }
    return v;
}
bool sam(node *u,node *v)
{
    while(u->f!=null)u=u->f;
    while(v->f!=null)v=v->f;
    return u==v;
}

void changeroot(node *u)
{
    access(u)->rev^=1;
    splay(u);
}
void link(node *u,node *v)
{
    changeroot(u);
    u->f=v;
}

void cut(node *u,node *v)
{
    changeroot(u);
    access(v);
    splay(v);
    v->ch[0]=v->ch[0]->f=null;
}
char ss[20];
int main()
{
    null=&Tnull;
    init(null);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            init(&tree[i]);
        }
        int u,v;
        for(int i=1;i<=m;i++)
        {
            scanf("%s%d%d",ss,&u,&v);
            if(ss[0]=='Q')
            {
                bool ok=sam(tree+u,tree+v);
                if(ok)printf("Yes\n");
                else printf("No\n");
            }
            else if(ss[0]=='C')
            {
                link(tree+u,tree+v);
            }
            else if(ss[0]=='D')
            {
                cut(tree+u,tree+v);
            }
        }
    }
    return 0;
}
