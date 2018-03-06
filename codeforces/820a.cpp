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

const int maxn=1111;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int main(){
    int c,v0,v1,a,l;
    cin>>c>>v0>>v1>>a>>l;
    int s=0;
    int ans=1;
    if(v0>=c){
        cout<<1<<"\n";
        return 0;
    }
    s=v0;
    while(true){
        ans++;
        if(v0+a<=v1){
            v0+=a;
        }else{
            v0=v1;
        }
        s-=l;
        if(s+v0>=c){
            cout<<ans<<"\n";
            return 0;
        }else{
            s+=v0;
        }
    }
    return 0;
}
