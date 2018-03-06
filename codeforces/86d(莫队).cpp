#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxn=2000005;

struct node{
    int l,r,id;
    node(int a=0,int b=0,int c=0):l(a),r(b),id(c){}
};

int pos[maxn];
ll a[maxn];
ll cnt[maxn];
int block;
int n,t;
vector<node> query;
ll ans[maxn];
ll res;

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}


bool cmp(const node &a,const node &b){
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    return pos[a.l]<pos[b.l];
}

void add(int x){
    res+=(2*cnt[a[x]]+1)*a[x];
    cnt[a[x]]++;
}
void del(int x){
    res+=(-2*cnt[a[x]]+1)*a[x];
    cnt[a[x]]--;
}

int main(){
    read(n),read(t);
    block= static_cast<int>(sqrt(n));
    for(int i=1;i<=n;i++){
        read(a[i]);
        pos[i]=i/block;
    }
    int l,r;
    for(int i=1;i<=t;i++){
        read(l),read(r);
        query.emplace_back(l,r,i);
    }
    sort(query.begin(),query.end(),cmp);
    l=1,r=0;
    for(const auto &i:query){
        while(l<i.l){
            del(l);
            l++;
        }
        while(l>i.l){
            l--;
            add(l);
        }
        while(r<i.r){
            r++;
            add(r);
        }
        while(r>i.r){
            del(r);
            r--;
        }
        ans[i.id]=res;
    }
    for(int i=1;i<=t;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}