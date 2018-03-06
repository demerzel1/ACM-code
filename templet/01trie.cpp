const int MAXN=1005;
int n;
ll a[MAXN];
struct Trie
{
    int ch[2],sz;
}T[MAXN*32];
int root=1,tot=1;

void init(){
    for(int i=1;i<=tot;i++) T[i].ch[0]=0,T[i].ch[1]=0,T[i].sz=0;
    tot=1;
}

void Insert(ll x)
{
    int o=root;
    T[o].sz++;
    for(int k=32;k>=0;k--)
    {
        int c=((x>>k)&1);
        if(!T[o].ch[c]) T[o].ch[c]=++tot;
        o=T[o].ch[c];
        T[o].sz++;
    }
}
void Delete(ll x)
{
    int o=root;
    T[o].sz--;
    for(int k=32;k>=0;k--)
    {
        int c=((x>>k)&1);
        o=T[o].ch[c];
        T[o].sz--;
    }
}
ll Query(ll x)
{
    int o=root;
    for(int k=32;k>=0;k--)
    {
        int c=((x>>k)&1);
        if(c==1)
        {
            if(T[o].ch[0]&&T[T[o].ch[0]].sz) o=T[o].ch[0];
            else o=T[o].ch[1],x^=(1<<k);
        }
        else
        {
            if(T[o].ch[1]&&T[T[o].ch[1]].sz) o=T[o].ch[1],x^=(1<<k);
            else o=T[o].ch[0];
        }
    }
    return x;
}
