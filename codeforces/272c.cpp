#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
using ll=long long;
ll num[MAXN];

template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[MAXN<<2];
    T lazy[MAXN<<2];
    void pushup(int o) {
        data[o]=max(data[ls],data[rs]);
    }
    void pushdown(int o) {
        if(lazy[o]) {
            lazy[ls]=lazy[o];
            lazy[rs]=lazy[o];
            data[ls]=data[o];
            data[rs]=data[o];
            lazy[o]=0;
        }
    }
    void build(int o,int l,int r) {
        lazy[o]=0;
        if(l==r) {
            data[o]=num[l];
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(o);
    }

    void update(int o,int l,int r,int x,int y,T v) {
        if(l>=x && r<=y) {
            lazy[o]=v;
            data[o]=v;
            return;
        }
        pushdown(o);
        int mid=(l+r)>>1;
        if(x<=mid) update(ls,l,mid,x,y,v);
        if(y>mid)  update(rs,mid+1,r,x,y,v);
        pushup(o);
    }
    T query(int o,int l,int r,int x,int y) {
        if(l>=x && r<=y) {
            return data[o];
        }
        pushdown(o);
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return max(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
    }
};

Segtree<long long> tree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    tree.build(1,1,n);
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int w,h;
        cin>>w>>h;
        ll t=tree.query(1,1,n,1,w);
        cout<<t<<"\n";
        tree.update(1,1,n,1,w,t+h);
    }
    return 0;
}
