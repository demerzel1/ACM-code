#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int maxn=200005;
const int INF=INT_MAX;
const double pi=acos(-1.0);
const double eps=1e-9;
 
template<class T>inline void read(T&x){
    int c;
    for(c=getchar();c<32&&~c;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}
 
int T;
ll p,q;
 
ll pre1[40];
ll pre[40];
int ind;
 
void init(){
    pre1[0]=1;
    for(int i=1;i<=31;i++){
        pre1[i]=pre1[i-1]*2;
    }
    pre[0]=1;
    for(int i=1;i<=31;i++){
        pre[i]=pre[i-1]+pre1[i];
        if(i>0&&pre[i-1]>1000000000){
            ind=i;
            break;
        }
    }
}
ll dfs(ll x,ll up){
    if(x==q)
        return 0;
    int t=lower_bound(pre,pre+ind,x-q)-pre;
    ll tt=x-q;
    if(pre[t]==tt||pre[t]-tt<=up){
        return t+1;
    }
    ll tmin=max(0LL,x+up-pre[t]);
    return t+1+min(dfs(x-pre[t-1],up+1),q-tmin);
}
 
int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%lld%lld",&p,&q);
        if(p<=q){
            printf("%lld\n",q-p);
            continue;
        }
        ll ans=dfs(p,0);
        printf("%lld\n",ans);
    }
    return 0;
}