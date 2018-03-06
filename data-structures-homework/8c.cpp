#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;

LL a1[200010],sum[200010],a2[200010];
int n,k;
int lowbit(int x){
    return x&(-x);
}
LL query(LL a[],int x){
    LL ret=0;
    while(x>=1){
        ret+=a[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(LL *a,int x,LL c){
    while(x<=n+1){
        a[x]+=c;
        x+=lowbit(x);
    }
    return;
}
LL x,y,z,ans;
char s[5];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%lld",&sum[i]);
    for(int i=1;i<=n;i++)
        sum[i]+=sum[i-1];
    while(k--){
        scanf("%s%d%d",&s,&x,&y);
        if(s[0]=='C'){
            scanf("%lld",&z);
            add(a1,x,z);
            add(a1,y+1,-z);
            add(a2,x,x*z);
            add(a2,y+1,-(y+1)*z);
        }
        else{
            ans=sum[y]-sum[x-1];
            ans+=(y+1)*query(a1,y)-query(a2,y);
            ans-=x*query(a1,x-1)-query(a2,x-1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
