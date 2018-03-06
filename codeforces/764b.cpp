#include<bits/stdc++.h>
using namespace std;

int num[200005];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&num[i]);
    }
    if(n%2==0) {
        for(int i=1; i<=n/2; i++) {
            if(i%2==0)
                printf("%d ",num[i]);
            else
                printf("%d ",num[n-i+1]);

        }
        for(int i=n/2+1; i<=n; i++) {
            if(i%2!=0)
                printf("%d ",num[i]);
            else
                printf("%d ",num[n-i+1]);

        }
    } else if(n%2!=0) {
        for(int i=1; i<=n/2; i++) {
            if(i%2==0)
                printf("%d ",num[i]);
            else
                printf("%d ",num[n-i+1]);

        }
        for(int i=n/2+1; i<=n; i++) {
            if(i%2==0)
                printf("%d ",num[i]);
            else
                printf("%d ",num[n-i+1]);

        }
    }
    return 0;
}
