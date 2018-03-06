#include<cstdio>
int a[1000001],b[10001],m,n,p[10001];

void KMP(){
    int i,j=0;
    int cnt=0;
    p[1]=0;
    for(i=2;i<=m;i++){
        while(j>0&&b[j+1]!=b[i]){
            j=p[j];
        }
        if(b[j+1]==b[i])
            j++;
        p[i]=j;
    }
    for(i=1;i<=n;i++){
        while(j>0&&b[j+1]!=a[i])
            j=p[j];
        if(b[j+1]==a[i])
            j++;
        if(j==m){
            printf("%d\n",i-m+1);
            return;
        }
    }
    printf("-1\n");
}

int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
            scanf("%d",&b[i]);
        KMP();
    }
    return 0;
}
