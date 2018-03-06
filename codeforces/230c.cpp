#include<bits/stdc++.h>
using namespace std;
char str[110][10100];
int s[110][10100];
int ds[110][20200];
int ans[105][20200];
int finans[20200]= {0};
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    bool flag=false;
    for(int i=1; i<=n; i++) {
        scanf("%s",str[i]);
        bool flags=false;
        for(int j=1; j<=m; j++) {
            s[i][j]=str[i][j-1]-'0';
            if(!flags&&s[i][j]) flags=true;
            ds[i][j]=s[i][j];
            ds[i][j+m]=s[i][j];
        }
        if(!flags) flag=true;
    }
    if(flag)
        printf("-1\n");
    else {
        for(int i=1; i<=n; i++) {
            int index;
            for(int j=1; j<=m; j++) {
                if(ds[i][j])
                    index=j;
            }
            for(int j=m+1; j<=2*m; j++) {
                if(ds[i][j])
                    index=j;
                else {
                    ans[i][j-m]=j-index;
                    //     if(j==2*m){
                    //         printf("%d ",ans[i][j-m]);
                    //     }
                }
            }
            //  printf("\n");
            for(int j=2*m; j>=m+1; j--) {
                if(ds[i][j])
                    index=j;
            }
            for(int j=m; j>=1; j--) {
                if(ds[i][j]) {
                    index=j;
                    ans[i][j]=0;
                    finans[j]+=ans[i][j];
                } else {
                    ans[i][j]=min(ans[i][j],index-j);
                    finans[j]+=ans[i][j];
                }
            }
        }
        int cnt=1000000;
        for(int i=1; i<=m; i++) {
            cnt=min(cnt,finans[i]);
        }
        printf("%d",cnt);
    }
    return 0;
}

//001010 001010
