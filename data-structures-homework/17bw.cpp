#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define LL long long
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const int MOD = 998244353;
const int N = 1e5+10;
const int maxx = 200010;
#define clc(a,b) memset(a,b,sizeof(a))
const double eps = 1e-8;
void fre() {freopen("in.txt","r",stdin);}
void freout() {freopen("out.txt","w",stdout);}
inline int read() {int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0') {if(ch=='-') f=-1; ch=getchar();}while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}return x*f;}

int a[N];
int n,m;
bool check(int k){
    queue<LL>q1;
    queue<LL>q2;
    if((n-1)%(k-1)!=0){
        for(int i=1;i<=k-1-(n-1)%(k-1);i++)
            q1.push(0);
    }
    for(int i=1;i<=n;i++){
        q1.push(a[i]);
    }
    LL sum=0;
    while(1){
        LL tem=0;
        for(int i=1;i<=k;i++){
            if(q1.size()==0&&q2.size()==0) break;
            int a1,a2;
            if(q1.size()==0){
                tem+=q2.front();
                q2.pop();
                continue;
            }
            if(q2.size()==0) {
               tem+=q1.front();
               q1.pop();
               continue;
            }
            a1=q1.front();
            a2=q2.front();
            if(a1<a2) {tem+=a1;q1.pop();}
            else {tem+=a2;q2.pop();}
        }
        sum+=tem;
        if(q1.size()==0&&q2.size()==0) break;
        q2.push(tem);
    }
    if(sum>m) return false;
    else return true;
}

int main(){
    // fre();
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int l=2,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
