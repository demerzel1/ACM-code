#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int dp[maxn][maxn];
string a,b;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(getline(cin,a),getline(cin,b)){
        memset(dp,0,sizeof(dp));
        int la=a.length();
        int lb=b.length();
        int ans=lcs(la-1,lb-1);
        printf("%d\n",ans);
    }
    return 0;
}
