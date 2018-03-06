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
typedef pair<int,int>ii;
const int maxn=1111;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int h,m;
int nh,nm;
char c;
int a;

int main(){
    cin>>h>>c>>m;
    cin>>a;
    int th=a/60;
    int tm=a%60;
    nm=tm+m;
    if(nm>=60){
        th++;
        nm-=60;
    }
    nh=(th+h)%24;
    printf("%02d:%02d\n",nh,nm);
    return 0;
}
