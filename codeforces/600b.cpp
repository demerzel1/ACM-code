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

const int maxn=200005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n,m;
int a[maxn];
int b[maxn];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    for(int i=0;i<m;i++){
        int ind=upper_bound(a,a+n,b[i])-a;
        cout<<ind<<" ";
    }
    return 0;
}
