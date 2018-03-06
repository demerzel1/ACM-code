#include <bits/stdc++.h>

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

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    double R,r;
    cin>>n>>R>>r;
    if(n==1){
        if(R>=r)
            printf("YES");
        else
            printf("NO");
        return 0;
    }
    double theta=asin(r/(R-r));
    double cnt=pi/theta;
    //cout<<cnt<<endl;
    if(fabs(cnt-n)<eps||cnt>n)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}