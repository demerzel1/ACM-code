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



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int a,b,c,d;
    int n;
    cin>>n;
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        if(a%2==0&&b%2==0)
            cout<<1<<endl;
        else if(a%2==0&&b%2!=0)
            cout<<2<<endl;
        else if(a%2!=0&&b%2==0)
            cout<<3<<endl;
        else
            cout<<4<<endl;
    }
    return 0;
}