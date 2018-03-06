#include<iostream>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<climits>
#define N 301
#define eps 1e-5
using namespace std;

#define maxn 105

int num[maxn][maxn];
int m,n;
int ans=INT_MIN;

void dfs(int d,int x,int sum){
    if(d==m+1){
        ans=max(ans,sum);
        return;
    }
    for(int i=x;i<=n;i++){
        if(n-i<m-d)
            continue;
        dfs(d+1,i+1,sum+num[d][i]);
    }
}

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    while(scanf("%d%d",&m,&n)!=EOF){
        ans=INT_MIN;
        memset(num,0,sizeof(num));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&num[i][j]);
        dfs(1,1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
