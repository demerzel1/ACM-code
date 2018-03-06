#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=60005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;


template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[maxn<<2];
    T lazy[maxn<<2];
    void pushup(int o) {
        data[o]=min(data[ls],data[rs]);
    }
    void setlazy(int o,int m,T v) {
        lazy[o]+=v;
        data[o]+=v;
    }
    void pushdown(int o,int m) {
        if(lazy[o]) {
            setlazy(ls,m-(m>>1),lazy[o]);
            setlazy(rs,m>>1,lazy[o]);
            lazy[o]=0;
        }
    }
    void build(int o,int l,int r) {
        lazy[o]=0;
        if(l==r) {
            data[o]=0;
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(o);
    }

    void update(int o,int l,int r,int x,int y,T v) {
        if(l>=x && r<=y) {
            setlazy(o,r-l+1,v);
            return;
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(x<=mid) update(ls,l,mid,x,y,v);
        if(y>mid)  update(rs,mid+1,r,x,y,v);
        pushup(o);
    }
    void updateone(int o,int l,int r,int index,T v) {
        if(l==r) {
            data[o]+=v;
            return;
        }
        int mid=(l+r)>>1;
        if(index<=mid) updateone(ls,l,mid,index,v);
        else updateone(rs,mid+1,r,index,v);
        pushup(o);
    }
    T query(int o,int l,int r,int x,int y) {
        if(l>=x && r<=y) {
            return data[o];
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return min(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
    }
};

Segtree<double> tree;
int n;
int a[maxn];
int last[maxn];


bool solve(double x){
    tree.build(1,1,n);
    for(int i=1;i<=n;++i){
        last[a[i]]=0;
    }
    for(int i=1;i<=n;i++){
        tree.updateone(1,1,n,i,x*i);
        tree.update(1,1,n,last[a[i]]+1,i,1);
        last[a[i]]=i;
        if(i==1)
            continue;
        if(tree.query(1,1,n,1,i-1)<=(i+1)*x)
            return true;
    }
    return false;
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        double l=0,r=1;
        double ans=1;
        for(int i=1;i<=22;++i){
            double mid=(l+r)/2;
            if(solve(mid)){
                ans=mid;
                r=mid;
            } else
                l=mid;
        }
        printf("%.10f\n",ans);
    }
    return 0;
}