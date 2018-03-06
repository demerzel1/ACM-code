
//a1=(sn-n*(n-1)/2*d)/n
//Sn^2=n(a1)^2+n(n-1)(2n-1)d^2/6+n(n-1)*d*a1  两个数学公式的运用

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

#define MOD m
int m;


struct mint{
    int x;
    mint():x(0){}
    mint(int s){ x=s;if(x<MOD && x>=0)return;
        x%=MOD;if(x<0)x+=MOD;
    }
    mint(ll s){int ts=s%MOD;if(ts<0)ts+=MOD;x=ts;}
    mint& operator+=(mint t){
        if( (x+=t.x) >=MOD)x-=MOD;return *this;}
    mint& operator-=(mint t){
        if( (x+=MOD-t.x) >=MOD)x-=MOD;return *this;}
    mint& operator*=(mint t){x=(ll)x*t.x%MOD;return *this;}
    mint& operator/=(mint t){return *this*=t.inv();}
    mint operator-()const{if(x)return MOD-x;return 0;}
    mint operator+(mint t)const{return mint(*this)+=t;}
    mint operator-(mint t)const{return mint(*this)-=t;}
    mint operator*(mint t)const{return mint(*this)*=t;}
    mint operator/(mint t)const{return mint(*this)/=t;}

    mint pow(ll k)const{
        mint r=1,a=x;
        for(;k;k>>=1,a*=a) if(k&1) r*=a;
        return r;
    }
    mint inv()const{return mint(x).pow(MOD-2);}
};
mint n;
bool cmp(const mint &a,const mint &b){
    return a.x<b.x;
}

mint s[3];
mint a[maxn];
mint b[maxn];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>m>>n.x;
    for(int i=0;i<n.x;i++){
        cin>>a[i].x;
        s[0]+=a[i];
        s[1]+=a[i]*a[i];
    }
    if(n.x==1){
        cout<<a[0].x<<' '<<0<<endl;
        return 0;
    }
    sort(a,a+n.x,cmp);
    for(int i=1;i<n.x;i++){
        mint d=a[i]-a[0];
        mint a1=(s[0]-n*(n-mint(1))/mint(2)*d)/n;
        mint t=n*a1*a1+n*(n-mint(1))*(mint(2)*n-mint(1))*d*d/mint(6)+n*(n-mint(1))*d*a1;
        if(t.x==s[1].x){
            b[0]=a1;
            for(int j=1;j<n.x;j++){
                b[j]=b[j-1]+d;
            }
            sort(b,b+n.x,cmp);
            bool flag=true;
            for(int j=0;j<n.x;j++){
                if(a[j].x!=b[j].x){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<a1.x<<' '<<d.x<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
