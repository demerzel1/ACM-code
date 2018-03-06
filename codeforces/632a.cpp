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

stack<string> stk;

int main(){
    ll n,p;
    ll ans=0;
    ll cnt=1;
    cin>>n>>p;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        stk.push(str);
    }
    stk.pop();
    ans=1;
    string t;
    while(!stk.empty()){
        t=stk.top();
        stk.pop();
        if(t=="half"){
            ans*=2;
        }else{
            ans=ans*2+1;
            cnt++;
        }
    }
    cout<<ans*p-(p/2)*cnt<<"\n";
    return 0;
}
