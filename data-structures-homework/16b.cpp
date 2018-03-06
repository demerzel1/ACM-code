#include<cstdio>
#include<cstring>
#define maxn 1000010
char p[maxn];
int f[maxn];
int main(){
    while(scanf("%s",p)){
        int n=strlen(p);
        printf("n=%d\n",n);
        if(n==1&&p[0]=='.')
            break;
        f[0]=0;
        f[1]=0;
        for(int i=1;i<n;i++){
            int j=f[i];
            while(j&&p[i]!=p[j])
                j=f[j];
            f[i+1]=(p[i]==p[j]?j+1:0);
        }
        if(f[n]>0&&n%(n-f[n])==0)
            printf("%d\n",n/(n-f[n]));
        else
            printf("1\n");
    }
    return 0;
}
