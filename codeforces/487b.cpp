#include <iostream>
using namespace std;
const int MAXN=100010;

int n,s,l;
int num[MAXN];
int maxto[MAXN];

template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[2][MAXN<<2];
    void pushup(int o) {
        data[0][o]=max(data[0][ls],data[0][rs]);
        data[1][o]=min(data[1][ls],data[1][rs]);
    }
    void build(int o,int l,int r) {
        if(l==r) {
            data[0][o]=num[l];
            data[1][o]=num[l];
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(o);
    }
    T querymax(int o,int l,int r,int x,int y) {
        if(l>=x && r<=y) {
            return data[0][o];
        }
        int mid=(l+r)>>1;
        if(y<=mid) return querymax(ls,l,mid,x,y);
        if(x>mid)  return querymax(rs,mid+1,r,x,y);
        return max(querymax(ls,l,mid,x,y),querymax(rs,mid+1,r,x,y));
    }
    T querymin(int o,int l,int r,int x,int y) {
        if(l>=x && r<=y) {
            return data[1][o];
        }
        int mid=(l+r)>>1;
        if(y<=mid) return querymin(ls,l,mid,x,y);
        if(x>mid)  return querymin(rs,mid+1,r,x,y);
        return min(querymin(ls,l,mid,x,y),querymin(rs,mid+1,r,x,y));
    }
    T query(int o,int l,int r,int x,int y){
        return querymax(o,l,r,x,y)-querymin(o,l,r,x,y);
    }
};


template<class T>struct Segtree1 {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[MAXN<<2];
    T lazy[MAXN<<2];
    void pushup(int o) {
        data[o]=min(data[ls],data[rs]);
    }
    void build(int o,int l,int r) {
        if(l==r) {
            data[o]=INT_MAX;
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(o);
    }
    void updateone(int o,int l,int r,int index,T v) {
        if(l==r) {
            data[o]=v;
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
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return min(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
    }
};

Segtree<int> tree;
Segtree1<int> dptree;

int binsearch(int now){
    int L=1,R=now,mid;
    while(R-L>3){
        mid=(R+L)/2;
        if(tree.query(1,1,n,mid,now)<=s)
            R=mid;
        else
            L=mid;
    }
    for(int i=L;i<=R;i++){
        if(tree.query(1,1,n,i,now)<=s)
            return i;
    }
    return -1;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    cin>>n>>s>>l;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    if(n<l){
        cout<<-1;
        return 0;
    }
    tree.build(1,1,n);
    dptree.build(1,1,n);
    for(int i=1;i<=n;i++){
//        cout<<i<<"\n";
        int le=binsearch(i);
//        cout<<"test\n";
        if(~le&&i-le+1>=l){
            if(le==1)
            dptree.updateone(1,1,n,i,1);
        else{
            int t1=dptree.query(1,1,n,i,i);
            int t2=1+dptree.query(1,1,n,le-1,i-l);
            dptree.updateone(1,1,n,i,min(t1,t2));
        }
        }
//        cout<<111<<"\n";
    }
    int ans=dptree.query(1,1,n,n,n);
    if(ans==INT_MAX||ans==-INT_MAX||ans==INT_MIN)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
