#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
typedef long long LL;
int c[maxn];
LL sl[maxn];
LL sr[maxn];
int nl[maxn];
int nr[maxn];
LL sum=0;
map<int,int> num;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) {
        scanf("%d",&c[i]);
        num[c[i]]++;
        sum+=c[i];
    }

    sort(c+1,c+n+1);
    int len=unique(c+1,c+n+1)-c-1;
    int L=-1;
    int R=-1;
    nl[0]=0;
    sl[0]=0;
    c[0]=c[1];
    for(int i=1; i<=len; i++) {
        nl[i]=nl[i-1]+num[c[i]];
        sl[i]=sl[i-1]+(LL)nl[i-1]*(c[i]-c[i-1]);
        if(sl[i]>k&&L==-1)
            L=i-1;
    }
    nr[len+1]=0;
    sr[len+1]=0;
    c[len+1]=c[len];
    for(int i=len; i>=1; i--) {
        nr[i]=nr[i+1]+num[c[i]];
        sr[i]=sr[i+1]+(LL)nr[i+1]*(c[i+1]-c[i]);
        if(sr[i]>k&&R==-1)
            R=i+1;
    }
    if(L>=R) {
        if(sum%n==0) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    } else {
        int Min=c[L]+(k-sl[L])/nl[L];
        int Max=c[R]-(k-sr[R])/nr[R];
        //    printf("min=%d cl=%d max=%d cr=%d\n",Min,c[L],Max,c[R]);
        if(Min>=Max) {
            if(sum%n==0) {
                printf("0\n");
            } else {
                printf("1\n");
            }
        } else {
            printf("%d\n",Max-Min);
        }

    }
    return 0;
}
