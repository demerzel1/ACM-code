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

int Tree[maxn];
inline int lowbit(int x){
    return (x&-x);
}

void add (int x,int value){
    for(int i=x;i<=maxn;i+=lowbit(i)){
        Tree[i]+=value;
    }
}

int get(int x){
    int sum=0;
    for(int i=x;i;i-=lowbit(i)){
        sum+=Tree[i];
    }
    return sum;
}

int n;

struct node{
    int l;
    int r;
    int id;
    node (int a=0,int b=0,int c=0){
        l=a;
        r=b;
        id=c;
    }
};

bool cmp(node a,node b){
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

bool cmp1(node a,node b){
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}

vector<node> v;
int ans[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(node(x,y,i));
    }
    sort(v.begin(),v.end(),cmp1);
    for(int i=0;i<n;i++){
        v[i].r=i+1;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=n-1;i>=0;i--){
//        cout<<v[i].l<<' '<<v[i].r<<' '<<v[i].id<<endl;
        ans[v[i].id]=get(v[i].r);
        add(v[i].r,1);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
