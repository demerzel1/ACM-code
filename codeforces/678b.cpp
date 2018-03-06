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
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

bool is_leap(int x) {
    if(x%400==0||(x%4==0&&x%100!=0))
        return true;
    return false;
}
                                                                                                   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int x;
    cin>>x;
    int res=0;
    bool flag=is_leap(x);
    while(true) {
        x++;
        if(is_leap(x))
            res+=2;
        else
            res++;
        if(res%7==0&&is_leap(x)==flag)
            break;
       }
    cout<<x<<endl;
    return 0;
}
