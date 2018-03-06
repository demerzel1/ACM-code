
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
#define maxs 1000005
LL s[maxs];
int main() {
    int k;
    scanf("%d",&k);
    while(k--) {
        memset(s,0,sizeof(s));
        int r;
        int n;
        scanf("%d%d",&r,&n);
        int l,t;
        LL w,h;
        LL sum=0;
        for(int i=0; i<n; i++) {
            scanf("%d%d%lld%lld",&l,&t,&w,&h);
            sum+=w*h;
            for(int j=l; j<=l+w-1&&j<=r-1; j++) {
                s[j]+=h;
            }
        }
        LL tsum=0;
        int left;
        for(left=0; left<=r-1; left++) {
            tsum+=s[left];
            if(tsum*2>=sum) {
                break;
            }
        }
        LL maxsum=tsum;
        int ans=left+1;
        for(int i=left+1; i<=r-1; i++) {
            maxsum+=s[i];
            if(maxsum!=tsum) {
                break;
            }
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
