#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=100005;
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

int n;
struct node{
    int l,r,val;
    node(){}
    node(int a,int b,int c):l(a),r(b),val(c){}
}tree[maxn];
int in[maxn];
int root;
int ans;
map<int,int> cnt;
map<int,int> mp;

void dfs(int x,int mn,int mx){
    if(tree[x].val>=mn&&tree[x].val<=mx){
        mp[tree[x].val]=1;
    }else{
        ans++;
        cnt[tree[x].val]++;
    }
    if(tree[x].l!=-1)
        dfs(tree[x].l,mn,min(mx,tree[x].val));
    if(tree[x].r!=-1)
        dfs(tree[x].r,max(mn,tree[x].val),mx);
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>tree[i].val>>tree[i].l>>tree[i].r;
        in[tree[i].l]++;
        in[tree[i].r]++;
    }
    for(int i=1;i<=n;++i){
        if(in[i]==0){
            root=i;
            break;
        }
    }
    dfs(root,-INF,INF);
    for(int i=1;i<=n;++i){
        if(mp[tree[i].val]==1&&cnt[tree[i].val]>0){
            mp[tree[i].val]=0;
            ans-=cnt[tree[i].val];
        }
    }
    cout<<ans<<'\n';
    return 0;
}