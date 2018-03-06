#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <iomanip>
#include <set>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MAXN=200005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

struct node{
    ll pos;
    ll len;
    ll sum;
    int id;
    bool operator < (node b)const{
        return pos<b.pos;
    }
}frog[MAXN];
int n,m;
int pos[MAXN];
pll mos[MAXN];

template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[MAXN<<2];
    void pushup(int o) {
        data[o]=max(data[ls],data[rs]);
    }
    void build(int o,int l,int r) {
        if(l==r) {
            data[o]=frog[l].sum;
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
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
        ll t=-1;
        int mid=(l+r)>>1;
        if(x<=mid)    t=max(t,query(ls,l,mid,x,y));
        if(y>=mid+1)  t=max(t,query(rs,mid+1,r,x,y));
        return t;
    }
};

Segtree<ll> tree;

pll ans[MAXN];

int gao(int x){
    int l=1;
    int r=upper_bound(pos+1,pos+1+n,x)-pos;
    r--;
//    cout<<"r= "<<r<<endl;
//    cout<<"query= "<<tree.query(1,1,n,1,r)<<endl;
    if(r==0||tree.query(1,1,n,1,r)<x)
        return -1;
    int res=-1;
    while(l<=r){
        int mid=(l+r)/2;
      //  cout<<tree.query(1,1,n,1,mid)<<" query\n";
        if(tree.query(1,1,n,1,mid)>=x){
//            cout<<r<<endl;
            r=mid-1;
            res=mid;
        }else
            l=mid+1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>frog[i].pos>>frog[i].len;
        frog[i].id=i;
    }
    for(int i=1;i<=m;i++){
        cin>>mos[i].first>>mos[i].second;
    }
    sort(frog+1,frog+n+1);
    for(int i=1;i<=n;i++){
        frog[i].sum=frog[i].pos+frog[i].len;
        pos[i]=frog[i].pos;
    }
    tree.build(1,1,n);
    multiset<pll> mset;
    for(int i=1;i<=m;i++){
        int p=gao(mos[i].first);
//        cout<<p<<endl;
        if(p!=-1){
            ans[frog[p].id].first++;
//            cout<<frog[p].id<<endl;
            frog[p].len+=mos[i].second;
            tree.updateone(1,1,n,p,mos[i].second);
            frog[p].sum=frog[p].pos+frog[p].len;
            while(!mset.empty()){
                auto it=mset.lower_bound(make_pair(frog[p].pos,0));
                if(it==mset.end()||frog[p].sum<it->first)
                    break;
                frog[p].len+=it->second;
                frog[p].sum+=it->second;
                ans[frog[p].id].first++;
                tree.updateone(1,1,n,p,it->second);
                mset.erase(it);
            }
        }else
            mset.insert(mos[i]);
    }
    for(int i=1;i<=n;i++){
        ans[frog[i].id].second=frog[i].len;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
    return 0;
}
