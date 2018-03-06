#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
int a[15];
int a1[15];

int main() {
    while(scanf("%d",&n)!=EOF) {

        memset(a,0,sizeof(a));
        memset(a1,0,sizeof(a1));
        scanf("%d",&m);
        int ans=m;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int flag=1;
        for(int i=0; i<n; i++) {
            flag*=a[i];
        }
        sort(a,a+n);
        for(int i=0; i<n; i++) {
            if(a[i]==0)
                a1[i]=1;
        }
        int x;
        for(int i=0; i<n; i++)
            if(a[i]>0) {
                x=i-1;
                break;
            }
        if(flag>0) {
            for(int i=0; i<n; i++) {
                if(a1[i]!=1)
                    ans*=a[i];
            }
        } else if(flag<0) {
            for(int i=0; i<n; i++) {
                if(a1[i]!=1)
                    ans*=a[i];
            }
            ans/=a[x];
        }
        printf("%d\n",ans);

    }
    return 0;
}

