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
const ld PI=acos(-1.0);
const ld EPS=1e-9;
inline int sgn(ld a){return a<-EPS? -1:a>EPS;}

ld Area(ld x1,ld y1,ld r1,ld x2,ld y2,ld r2) {
    ld d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    if(d>=(r1+r2)*(r1+r2))
        return 0;
    else if((r1-r2)*(r1-r2)>=d) {
        if(r1>r2)
            return PI*r2*r2;
        else
            return PI*r1*r1;
    } else {
        ld a1=2*acosl((r1*r1+d-r2*r2)/2/r1/sqrt(d));
        ld a2=2*acosl((r2*r2+d-r1*r1)/2/r2/sqrt(d));
        ld ans=r1*r1*a1/2+r2*r2*a2/2-r1*r1*sinl(a1)/2-r2*r2*sinl(a2)/2;
        return ans;
    }
}


int main(){
    ld x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    cout<<fixed<<setprecision(15);
    cout<<Area(x1,y1,r1,x2,y2,r2)<<"\n";
    return 0;
}
