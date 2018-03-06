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
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int main(){
    int h1,h2;
    int a,b;
    cin>>h1>>h2>>a>>b;
    int t=14;
    int ans=0;
    while(true){
        int up=(22-t)*a;
        h1+=up;
        if(h1>=h2){
            cout<<ans<<endl;
            return 0;
        }
        ans++;
        h1-=12*b;
        t=10;
        if(ans>1&&b>=a){
            cout<<-1<<endl;
            return 0;
        }
    }
    return 0;
}
