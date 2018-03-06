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

struct node{
    int f;
    int id;
    node(int a=0,int b=0){
        f=a;
        id=b;
    }
};

bool cmp(node a,node b){
    return a.f<b.f;
}

vector<node> v;

int main(){
    int n;
    cin>>n;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        v.emplace_back(node(t,i));
    }
    sort(v.begin(),v.end(),cmp);
    ll ans=0;
    for(int i=0;i<v.size()-1;i++){
        ans+=(ll)abs(v[i].id-v[i+1].id);
    }
    cout<<ans<<endl;

    return 0;
}
