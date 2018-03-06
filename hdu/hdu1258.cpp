#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[23],ans[23];
int flag=0;
void dfs(int index,int cnt,int sum) {
    int x;
    if(sum>t)
        return;
    if(sum==t) {
        flag=1;
        for(int i=0; i<cnt; i++) {
            if(i<cnt-1)
                printf("%d+",ans[i]);
            else
                printf("%d\n",ans[i]);
        }
    }
    x=-1;
    for(int i=index; i<n; i++) {
        if(x!=a[i]) {
           // printf("a[i]=%d\n",a[i]);
            ans[cnt]=a[i];
            x=a[i];
            dfs(i+1,cnt+1,sum+a[i]);
        }
    }
}

int main() {
    while(scanf("%d%d",&t,&n)) {
        if(t==0&&n==0)
            break;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        flag=0;
        printf("Sums of %d:\n",t);
        dfs(0,0,0);
        if(!flag)
            printf("NONE\n");
    }
    return 0;
}
