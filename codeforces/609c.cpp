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

const int maxn=100005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    int aver=0;
    int t=0;
    int ans=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    aver=sum/n;
    sort(a,a+n);
    t=sum%n;
    for(int i=1;i<=t;i++){
        a[n-i]--;
    }
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-aver);
    }
    ans/=2;
    cout<<ans<<"\n";
    return 0;
}
