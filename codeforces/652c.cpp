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


int n,m;
int num[maxn];
int f[maxn];
int ind[maxn];
ll ans=0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        ind[num[i]]=i;
        f[i]=n;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(ind[a]>ind[b])
            swap(a,b);
        f[ind[a]]=min(f[ind[a]],ind[b]-1);
    }
    for(int i=n-1;i>=1;i--){
        f[i]=min(f[i],f[i+1]);
    }
    for(int i=1;i<=n;i++){
        ans+=(ll)(f[i]-i+1);
//        cout<<f[i]<<' '<<i<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
