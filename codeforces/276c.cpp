#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
#define maxn 200005
using ll=long long;

template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[MAXN<<2];
    T lazy[MAXN<<2];
    void pushup(int o) {
        data[o]=data[ls]+data[rs];
    }
    void setlazy(int o,int m,T v) {
        lazy[o]+=v;
        data[o]+=m*v;
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
        return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
    }
};

Segtree<long long> tree;

ll a[maxn];
int cnt[maxn];

int main(){
    int l,r;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    tree.build(1,1,n);
    for(int i=0;i<q;i++){
        cin>>l>>r;
        cout<<111;
        tree.update(1,1,n,l,r,1);
    }
    cout<<222;
    for(int i=0;i<n;i++){
        int t=tree.query(1,1,n,i,i);
        cnt[i]=t;
        cout<<t<<"\n";
    }
    sort(a,a+n);
    sort(cnt,cnt+n);
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(ll)a[i]*cnt[i];
    }
    cout<<ans<<"\n";
    return 0;
}
