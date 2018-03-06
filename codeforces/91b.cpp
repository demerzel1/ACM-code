#include <iostream>
#include <climits>

using namespace std;

const int MAXN=100010;

int num[MAXN];

template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[MAXN<<2];
    void pushup(int o) {
        data[o]=min(data[ls],data[rs]);
    }
    void build(int o,int l,int r) {
        if(l==r) {
            data[o]=num[l];
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
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

int n;
int ans[MAXN];

int solve (int x,int t) {
    int l=x,r=n;
    while(r-l>=3){
        int mid=(l+r)>>1;
       // cout<<"mid= "<<mid<<endl;
        if(tree.query(1,1,n,mid,r)<t){
            l=mid;
            continue;
        }
        if(tree.query(1,1,n,l,mid)<t){
            r=mid;
            continue;
        }
        break;
    }
   // cout<<l<<' '<<r<<endl;
    if(r-l>=3)
        return -1;
    int ans=0;
    for(int i=r;i>=l;i--){
        if(num[i]<t){
            ans=i;
            break;
        }
    }
    if(ans==0)
        return -1;
    ans=ans-x-1;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    tree.build(1,1,n);
    for(int i=1;i<=n;i++){
     //   cout<<"i= "<<i<<endl;
        ans[i]= solve(i,num[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}