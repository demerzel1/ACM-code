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

const int maxn=500005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n;
ll p[maxn];
string s;
ll dpz[maxn];
ll dpf[maxn];
ll dpzz[maxn];
ll dpff[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cin>>s;
    for(int i=0;i<n;i++){
        if(i==0){
            if(s[i]=='A'){
                dpz[i]=p[i];
                dpzz[i]=0;
            }else{
                dpz[i]=0;
                dpzz[i]=p[i];
            }
        }else{
            if(s[i]=='A'){
                dpz[i]=dpz[i-1]+p[i];
                dpzz[i]=dpzz[i-1];
            }else{
                dpz[i]=dpz[i-1];
                dpzz[i]=dpzz[i-1]+p[i];
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='A'){
            dpf[i]=dpf[i+1]+p[i];
            dpff[i]=dpff[i+1];
        }else{
            dpf[i]=dpf[i+1];
            dpff[i]=dpff[i+1]+p[i];
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='B')
            ans+=p[i];
    }
    for(int i=0;i<n;i++){
        if(i==0){
           ans=max(ans,dpz[i]+dpff[i+1]);
           ans=max(ans,dpf[i]);
           continue;
        }
        ans=max(ans,dpz[i]+dpff[i+1]);
        ans=max(ans,dpzz[i-1]+dpf[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
