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
    double n,a;
    cin>>n>>a;
    double t=180.0/n;
    int cnt=(int)(a/t);
   // cout<<cnt<<"\n";
    if(cnt==0){
        cout<<"1 2 "<<n<<"\n";
        return 0;
    }
    if(cnt>=n){
        cout<<"1 2 3\n";
        return 0;
    }
    double ta=a-cnt*t;
    double tb=(cnt+1)*t-a;
    if(ta-tb<0){
        cout<<"1 2 "<<n-cnt+1<<"\n";
    }else{
        cnt++;
        cout<<"1 2 "<<n-cnt+1<<"\n";
    }
    return 0;
}
