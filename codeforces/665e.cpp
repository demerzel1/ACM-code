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
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int ch[maxn*32][2];
int n;
int son[maxn*32];
int pre[maxn];
int sz=1;
ll ans;

void _insert(int x){
    int u=1;
    int t;
    for(int i=31;i>=0;i--){
        t=(x>>i)&1;
        if(!ch[u][t])
            ch[u][t]=++sz;
        son[u]++;
        u=ch[u][t];
    }
    son[u]++;
    return;
}

void query(int x,int k){
    int u=1;
    int t1,t2;
    for(int i=31;i>=0;i--){
        t1=(x>>i)&1;
        t2=(k>>i)&1;
        if(t2==0){
            ans+=son[ch[u][!t1]];
            u=ch[u][t1];
        }else{
            u=ch[u][!t1];
        }
        if(u==0)
            break;
    }
    ans+=son[u];
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int k;
    cin>>n>>k;
    pre[0]=0;
    _insert(0);
    int t;
    for(int i=1;i<=n;i++){
        cin>>t;
        pre[i]=pre[i-1]^t;
        query(pre[i],k);
        _insert(pre[i]);
       // cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
