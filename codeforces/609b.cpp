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

const int maxn=15;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int cnt[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            ans+=cnt[i]*cnt[j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
