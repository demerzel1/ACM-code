#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=10005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

int n,m;

struct node{
    int l,r,id,t;
}query[10005];

struct node1{
    int p,c,past;
}change[10005];
int block;
int pos[10005];
int ans[maxn];
int a[maxn];
int last[maxn];
int num[1000005];
int cnt1,cnt2;
int sum;

//排序时加上时间维度，以最近的一次修改为时间排序方式
bool cmp(const node &a,const node&b){
    if(pos[a.l]==pos[b.l]&&a.r==b.r)
        return a.t<b.t;
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    return pos[a.l]<pos[b.l];
}

void add(int x){
    ++num[a[x]];
    if(num[a[x]]==1)
        ++sum;
}

void del(int x){
    --num[a[x]];
    if(num[a[x]]==0)
        --sum;
}

void change_color(int p,int c,int l,int r){
    if(p>=l&&p<=r){
        del(p);
        a[p]=c;
        add(p);
    } else
        a[p]=c;
}


void solve(){
    int l=1,r=0;
    for(int i=1;i<=cnt1;++i){
        //先完成两次查询间的修改操作
        for(int j=query[i-1].t+1;j<=query[i].t;++j)
            change_color(change[j].p,change[j].c,l,r);
        for(int j=query[i-1].t;j>query[i].t;--j)
            change_color(change[j].p,change[j].past,l,r);
        //正常莫队
        int tl=query[i].l,tr=query[i].r;
        while(l<tl){
            del(l);
            ++l;
        }
        while(l>tl){
            --l;
            add(l);
        }
        while(r<tr){
            ++r;
            add(r);
        }
        while(r>tr){
            del(r);
            --r;
        }
        ans[query[i].id]=sum;
    }
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    scanf("%d%d",&n,&m);
    int sz=sqrt(n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        last[i]=a[i];
        pos[i]=i/sz;
    }
    char op[5];
    int t1,t2;
    for(int i=1;i<=m;++i){
        scanf("%s",op);
        scanf("%d%d",&t1,&t2);
        if(op[0]=='Q'){
            query[++cnt1].l=t1;
            query[cnt1].r=t2;
            query[cnt1].id=cnt1;
            query[cnt1].t=cnt2;
        }else{
            change[++cnt2].p=t1;
            change[cnt2].c=t2;
            change[cnt2].past=last[t1];
            last[t1]=t2;
        }
    }
    sort(query+1,query+cnt1+1,cmp);
    solve();
    for(int i=1;i<=cnt1;++i)
        printf("%d\n",ans[i]);
    return 0;
}