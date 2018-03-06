#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=1<<20;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;

template<class T>inline void read(T&x){
    int c;
    for(c=getchar();c<32&&~c;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}

struct node{
    int l;
    int r;
    int id;
    node(int a=0,int b=0,int c=0):l(a),r(b),id(c){}
};

vector<node> query;

ll a[maxn];
ll pre[maxn];
int pos[maxn];
int block;
int n,m,k;
ll res;
ll ans[maxn];
ll cnt[maxn];


bool cmp(const node &a,const node &b){
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    return pos[a.l]<pos[b.l];
}

void del (int x) {
    cnt[pre[x]]--;
    res-=cnt[pre[x]^k];
}

void add (int x) {
    res+=cnt[pre[x]^k];
    cnt[pre[x]]++;
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    auto sz=(int)sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
        pos[i]=i/sz;
    }
    int _,__;
    for(int i=0;i<m;i++){
        cin>>_>>__;
        query.emplace_back(_,__,i);
    }
    sort(query.begin(),query.end(),cmp);
    int l=1,r=0;
    cnt[0]=1;
    for(const auto &i:query){
        while(l<i.l){
            del(l-1);
            l++;
        }
        while(l>i.l){
            l--;
            add(l-1);
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
    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}