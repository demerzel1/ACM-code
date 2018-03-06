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
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int a[maxn];
int cnt[maxn];
int d[maxn];


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=m)
            cnt[a[i]]++;
    }
    for(int i=m;i>0;i--){
        for(int j=i;j<=m;j+=i){
            d[j]+=cnt[i];
        }
    }
    ll ans=-1;
    ll ansi=-1;
    for(int i=1;i<=m;i++){
        if(d[i]>ans){
            ans=d[i];
            ansi=i;
        }
    }
    printf("%lld %lld\n",ansi,ans);
    for(int i=1;i<=n;i++){
        if(ansi%a[i]==0)
            cout<<i<<" ";
    }
    return 0;
}
