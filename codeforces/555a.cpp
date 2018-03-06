#include<bits/stdc++.h>
using namespace std;

int num[100005];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==1) {
        printf("0");
        return 0;
    }
    int b;
    for(int i=0; i<k; i++) {
        int a;
        scanf("%d",&a);
        int num1;
        scanf("%d",&num1);
        if(num1==1) {
            b=a;
            num[0]=num1;
            for(int j=1; j<a; j++) {
                scanf("%d",&num[j]);
            }
        } else {
            for(int j=1; j<a; j++)
                scanf("%d",&num1);
        }
    }
    int m=0;
    for(int i=0; i<b; i++) {
        if(num[i]==m+1)
            m++;
        else
            break;

    }
    int ans=2*(n-m)-k+1;
    printf("%d\n",ans);
    return 0;

}
