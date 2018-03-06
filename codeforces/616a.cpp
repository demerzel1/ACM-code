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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    string a,b;
    cin>>a>>b;
    int sza=a.size(),szb=b.size();
    int i;
    for(i=0;i<sza;i++){
        if(a[i]!='0')
            break;
    }
    a=a.substr(i);
    //cout<<a<<endl;
    int j;
    for(j=0;j<szb;j++){
        if(b[j]!='0')
            break;
    }
    b=b.substr(j);
    sza=a.size();
    szb=b.size();
    if(sza==szb){
        for(i=0;i<sza;i++){
            if(a[i]!=b[i])
                break;
        }
        if(i==sza){
            cout<<'='<<endl;
            return 0;
        }
        if(a[i]<b[i])
            cout<<'<'<<endl;
        else
            cout<<'>'<<endl;
    }else{
        if(sza<szb)
            cout<<'<'<<endl;
        else
            cout<<'>'<<endl;
        return 0;
    }
    return 0;
}
