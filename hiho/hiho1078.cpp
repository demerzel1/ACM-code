#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;

int num[MAXN];

template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[MAXN<<2];
    T lazy[MAXN<<2];
    void pushup(int o) {
        data[o]=data[ls]+data[rs];
    }
    void setlazy(int o,int m,T v) {
        lazy[o]=v;
        data[o]=m*v;
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
            setlazy(o,r-l+1,v);
            return;
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(x<=mid) update(ls,l,mid,x,y,v);
        if(y>mid)  update(rs,mid+1,r,x,y,v);
        pushup(o);
    }
    T query(int o,int l,int r,int x,int y) {
        if(l>=x && r<=y) {
     //       pushdown(o,r-l+1);
            return data[o];
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
    }
};

Segtree<int> tree;

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    tree.build(1,1,n);
    int t;
    scanf("%d",&t);
    int op,l,r,v;
    while(t--){
        scanf("%d",&op);
        if(op==0){
            scanf("%d%d",&l,&r);
            cout<<tree.query(1,1,n,l,r)<<"\n";
        }
        else if(op==1){
            scanf("%d%d%d",&l,&r,&v);
            tree.update(1,1,n,l,r,v);
        }
    }
    return 0;
}
