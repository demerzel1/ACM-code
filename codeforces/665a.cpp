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

const int maxn=200005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int a,ta;
int b,tb;
int h,m;
char c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>a>>ta>>b>>tb;
    cin>>h;
    cin>>c;
    cin>>m;
    int start=h*60+m;
    int End=start+ta;
    int l=300;
    int r=24*60-1;
    int ans=0;
    for(int i=l;i<=r;i+=b){
        if(i+tb>start&&i<End)
            ans++;
        if(i>=End)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
