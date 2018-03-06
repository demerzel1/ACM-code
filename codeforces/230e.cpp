#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000+10
long long int a[MAXN];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    long long int sum=0;
    for(int i=0; i<m; i++) {
        long long int sou,des;
        scanf("%I64d%I64d",&sou,&des);
        a[sou]++;
        a[des]++;
    }
    for(long long int i=1; i<=n; i++) {
        long long d=a[i];
        sum+=d*(d-1)-d*(n-d-1)+(n-d-1)*(n-d-2);
    }
    long long int ans=sum/6;
    printf("%I64d\n",ans);


    return 0;
}
