#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int dp[maxn][maxn];
int a[maxn],b[maxn];
int lcs(int i,int j){
    if(i==-1||j==-1)  return 0;
    if(dp[i][j]!=0) return dp[i][j];
    if(i>=0&&j>=0&&a[i]==b[j]){
        dp[i][j]=lcs(i-1,j-1)+1;
        return dp[i][j];
    }
    if(i>=0&&j>=0&&a[i]!=b[j]){
        dp[i][j]=max(lcs(i-1,j),lcs(i,j-1));
        return dp[i][j];
    }
    return dp[i][j];
}

int main(){
    int la,lb;
    int cnt=0;
    while(scanf("%d%d",&la,&lb)){
        memset(dp,0,sizeof(dp));
        if(la==0&&lb==0)
            break;
        cnt++;
        for(int i=0;i<la;i++)   scanf("%d",&a[i]);
        for(int i=0;i<lb;i++)   scanf("%d",&b[i]);
        int ans=lcs(la-1,lb-1);
        printf("Twin Towers #%d\n",cnt);
        printf("Number of Tiles : %d\n\n",ans);
    }
    return 0;
}

