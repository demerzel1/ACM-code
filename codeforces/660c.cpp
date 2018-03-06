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

const int maxn=300005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n,k;
int a[maxn];
int sum[maxn];
int res=-1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+(1-a[i]);
    }
    int l=1,ansl=1,ansr=1,r=1;
    int ans=0;
    int cnt=0;
    while(r<=n){
        while(a[r]==1)
            r++;
        if(a[r]==0&&r<=n)
            cnt++;
        while(sum[r]-sum[l-1]<=k&&r<=n)
            r++;
        if(r-l>res){
            res=r-l;
            ansl=l;
            ansr=r-1;
        }
        while(l<=r&&sum[r]-sum[l-1]>k)
            l++;
        if(r<=n&&r-l+1>res){
            res=r-l+1;
            ansl=l;
            ansr=r;
        }
    }
    cout<<ansr-ansl+1<<endl;
    for(int i=ansl;i<=ansr;i++)
        a[i]=1;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}
