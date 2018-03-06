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
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n,s;
int a[maxn];
int sum[maxn];

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        int l=1,r=1,ans=INF;
        while(r<=n){
            while(sum[r]-sum[l-1]<s&&r<=n) r++;
            if(r-l<ans){
                ans=r-l+1;
            }
            l++;
        }
        if(ans==n+1)
            ans=0;
        cout<<ans<<endl;
    }
    return 0;
}
