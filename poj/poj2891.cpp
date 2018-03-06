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
#include <set>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
#include<climits>
using namespace std;
#define maxn 100005
typedef long long ll;

ll b[maxn],c[maxn];

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}



int main(){
    int k;
    while(cin>>k){
        for(int i=0; i<k; i++) {
            cin>>b[i]>>c[i];
        }
        bool flag=true;
        ll x,y,tb=b[0],tc=c[0];
        for(int i=1; i<k; i++) {
            ll g=exgcd(tb,b[i],x,y);
            ll C=c[i]-tc;
            if(C%g!=0) {
                flag=false;
                break;
            }
            x=C/g*x%(b[i]/g);
            tc=tc+x*tb;
            tb=tb/g*b[i];
            tc=tc%tb;
        }
        if(!flag)
            cout<<"-1\n";
        else{
            tc%=tb;
            if(tc<0)
                tc+=tb;
            cout<<tc<<"\n";
        }
    }

    return 0;
}
