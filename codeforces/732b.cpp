#include<bits/stdc++.h>
using namespace std;
int a[505];
int main() {
    int n,k;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1; i<n; i++) {
        if(a[i-1]+a[i]<k){
            int c=k-a[i-1]-a[i];
            ans+=c;
            a[i]+=c;
        }
    }
    printf("%d\n",ans);
    for(int i=0; i<n; i++) {
       printf("%d ",a[i]);
    }
    return 0;
}

