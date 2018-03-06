#include<bits/stdc++.h>
using namespace std;
#define maxn 2005

int cnt1[10005];
long long  cnt2[10005];
int sum=0;
double ans;
int a[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=0; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            cnt1[a[i]-a[j]]++;
            sum++;
            //  printf("ai=%d aj=%d sum=%d\n",a[i],a[j],sum);
        }
    }
    for(int i=1; i<=5000; i++) {
        for(int j=1; j<=5000; j++) {
            cnt2[i+j]+=cnt1[i]*cnt1[j];
            //  printf("i=%d j=%d c1i")
        }
    }
    for(int i=0; i<=5000; i++) {
        for(int j=i-1; j>=0; j--) {
            ans+=1.0*cnt1[i]*cnt2[j]/sum/sum/sum;
            //  ans+=(1.0*cnt1[i]/sum)*(1.0*cnt2[j]/(sum*sum));
            //   cout<<111<<endl;
        }
    }
    printf("%.15f",ans);
    return 0;
}
