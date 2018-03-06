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

const int maxn=100005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n,m;
int a[maxn];
int b[maxn];
int ans;
int tans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<n;i++){
        int pos=lower_bound(b,b+m,a[i])-b;
        if(pos==0){
            tans=abs(a[i]-b[pos]);
        }else if(pos==m){
            tans=abs(a[i]-b[pos-1]);
        }else{
            tans=min(abs(a[i]-b[pos]),abs(a[i]-b[pos-1]));
        }
        ans=max(ans,tans);
    }
    cout<<ans<<endl;
    return 0;
}