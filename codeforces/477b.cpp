#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int ans[4*maxn];
void pre(int n){
    int cnt=1;
    int index=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=2;j++){
            ans[index]=cnt;
            cnt++;
            index++;
        }
        cnt++;
        ans[index]=cnt;
        cnt+=2;
        index++;
    }
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    pre(n);
    printf("%d\n",ans[n*4]*k);
    for(int i=1;i<=n;i++){
        for(int j=(i-1)*4+1;j<=i*4;j++)
            printf("%d ",ans[j]*k);
        printf("\n");
    }
    return 0;
}
