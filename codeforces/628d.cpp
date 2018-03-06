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

const int maxn=2005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}
const ll mod=1e9+7;

string a,b;
int m,d,sz;

int num[maxn];
ll dp[maxn][maxn];

ll dfs(int l,int pre,bool judge){
    if(l==sz)   return pre==0;
    if(!judge&&dp[l][pre]!=-1)
        return dp[l][pre];
    ll ans=0;
    int ind=judge?num[l]:9;
    for(int i=0;i<=ind;i++){
        if(l%2==0&&i==d)    continue;
        if(l%2==1&&i!=d)    continue;
        ans=(ans+dfs(l+1,(pre*10+i)%m,judge&&i==ind))%mod;
    }
    if(!judge)  dp[l][pre]=ans;
    return ans;
}

ll solve(string s){
    int len=s.size();
    for(int i=0;i<len;i++)
        num[i]=s[i]-'0';
    return dfs(0,0,1);
}

bool gao(string s){
    int yu=0;
    for(int i=0;i<sz;i++){
        int x=s[i]-'0';
        yu=(yu*10+x)%m;
        if((i%2==0&&x==d)||(i%2==1&&x!=d))
            return false;
    }
    return yu==0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    cin>>m>>d;
    cin>>a>>b;
    sz=a.size();
//    cout<<solve(b)<<' '<<solve(a)<<endl;
    cout<<(solve(b)-solve(a)+gao(a)+mod)%mod<<endl;
    return 0;
}