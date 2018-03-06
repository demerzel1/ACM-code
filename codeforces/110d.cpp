#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Max 1000000005
vector<ll> lucknum;
void dfs(ll x) {
    lucknum.push_back(x);
    if(x<Max) {
        dfs(x*10+4);
        dfs(x*10+7);
    }
    return;
}

int main() {
    dfs(0);
    int len=lucknum.size();
    sort(lucknum.begin(),lucknum.end());
    int pl,pr,vl,vr,k;
//    for(int i=0;i<len;i++)
//        printf("%lld ",lucknum[i]);
    scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k);
    ll sum=0;
    for(int i=1; i<len-k&&lucknum[i]<max(pr,vr); i+=k) {
        int a1=0,a2=0,a3=0,a4=0;
        if(pl<=lucknum[i]&&lucknum[i-1]<=pr) {
            int a=0;
            if(lucknum[i]<=pr&&lucknum[i-1]<pl)
                a=lucknum[i]-pl+1;
        //    printf("aaa%d ",lucknum[i]-pl+1);
            if(lucknum[i]>pr&&lucknum[i-1]<=pl)
                a=pr-pl+1;
            if(lucknum[i-1]>pl&&lucknum[i]<=pr)
                a=lucknum[i]-lucknum[i-1]+1;
            if(lucknum[i-1]>pl&&lucknum[i]>pr)
                a=pr-lucknum[i-1]+1;
            a1=a;
        }
        if(vl<lucknum[i]&&lucknum[i-1]<=vr) {
            int a=0;
            if(lucknum[i]<=vr&&lucknum[i-1]<vl)
                a=lucknum[i]-vl+1;
            if(lucknum[i]>vr&&lucknum[i-1]<=vl)
                a=vr-vl+1;
            if(lucknum[i-1]>vl&&lucknum[i]<=vr)
                a=lucknum[i]-lucknum[i-1]+1;
            if(lucknum[i-1]>vl&&lucknum[i]>vr)
                a=vr-lucknum[i-1]+1;
            a2=a;
        }
   //     printf("%d %d\n",lucknum[i+k],lucknum[i+k+1]);
        if(vl<lucknum[i+k]&&lucknum[i+k-1]<=vr) {
                int a=0;
            if(lucknum[i+k]<=vr&&lucknum[i+k-1]<vl)
                a=lucknum[i+k]-vl+1;
            if(lucknum[i+k]>vr&&lucknum[i+k-1]<=vl)
                a=vr-vl+1;
            if(lucknum[i+k-1]>vl&&lucknum[i+k]<=vr)
                a=lucknum[i+k]-lucknum[i+k-1]+1;
            if(lucknum[i+k-1]>vl&&lucknum[i+k]>vr)
                a=vr-lucknum[i+k-1]+1;
            a3=a;

        }
        if(pl<lucknum[i+k]&&lucknum[i+k-1]<=pr) {
            int a=0;
            if(lucknum[i+k]<=pr&&lucknum[i+k-1]<pl)
                a=lucknum[i+k]-pl+1;
            if(lucknum[i+k]>pr&&lucknum[i+k-1]<=pl)
                a=vr-vl+1;
            if(lucknum[i+k-1]>pl&&lucknum[i+k]<=pr)
                a=lucknum[i+k]-lucknum[i+k-1]+1;
            if(lucknum[i+k-1]>pl&&lucknum[i+k]>pr)
                a=pr-lucknum[i+k-1]+1;
            a4=a;
        }
        printf("%d %d %d %d\n",a1,a2,a3,a4);
        sum+=a1*a3+a2*a4;
    }
   cout<<sum<<endl;
    double ans=(double)sum/(pr-pl+1)/(vr-vl+1);
    cout<<setiosflags(ios::fixed)<<setprecision(12)<<ans;
    return 0;
}
