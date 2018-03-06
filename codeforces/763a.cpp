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

int n;
int u[maxn];
int v[maxn];
int c[maxn];
int cnt;
int a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n-1;i++)
        cin>>u[i]>>v[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n-1;i++){
        if(c[u[i]]!=c[v[i]]){
            cnt++;
            a[u[i]]++;
            a[v[i]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==cnt){
            cout<<"YES"<<endl;
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}