#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=205;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

vector<int> v;
int n;
int x;

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>x;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        v.emplace_back(a);
    }
    int cnt=x;
    for(const auto &i:v){
        if(i<x)
            cnt--;
        if(i==x)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}