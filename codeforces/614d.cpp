#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

struct person {
    int value;
    int index;
} p[maxn];
long long sum[maxn];

bool cmpval(person a,person b) {
    return a.value<b.value;
}

bool cmpindex(person a,person b) {
    return a.index<b.index;
}

int main() {
    int n,a,cf,cm;
    long long m;
    long long ans=-1;
    long long indexmax=0,indexmin=0,valmin=0;
    cin>>n>>a>>cf>>cm>>m;
    for(int i=0; i<n; i++) {
        scanf("%d",&p[i].value);
        p[i].index=i;
    }
    sort(p,p+n,cmpval);
    sum[0]=0;
    for(int i=0; i<n; ++i) {
        sum[i+1]=sum[i]+p[i].value;
    }
    long long money=0;
    int j=0;
    int i;
    long long tans=0;
    long long tmin=0;
    long long moneyForMin;
    for(i=0,j=0;i<=n;i++){
        money=(long long)a*(n-i)-(sum[n]-sum[i]);
        if(money>m)
            continue;
        tans=(n-i)*cf;
        moneyForMin=m-money;
        while(j<i&&(long long)p[j].value*j-sum[j]<=moneyForMin){
                ++j;
            }
            if(j==0){
                tmin=a;
            }
            else{
                tmin=min((moneyForMin+sum[j])/j,(long long)a);
            }
            tans+=(long long)tmin*cm;
            if(ans<tans){
                ans=tans;
                indexmax=i;
                indexmin=j-1;
                valmin=tmin;
            }
        }
         for(i=indexmax;i<n;i++){
            p[i].value=a;
        }
         for(i=0;i<=indexmin;i++){
            p[i].value=valmin;
        }
        sort(p,p+n,cmpindex);
        cout<<ans<<endl;
        for(i=0;i<n;i++){
            printf("%d ",p[i].value);
        }
        cout<<endl;
        return 0;
    }

