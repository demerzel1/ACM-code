#include<bits/stdc++.h>
using namespace std;
#define maxn 505

int c[maxn];
int n;
int d[maxn][maxn];

int dp(int i,int j){
    if(i>j) return 0;
    if(i==j) return 1;
    if(d[i][j]!=-1) return d[i][j];
    int tans=dp(i+1,j)+1;
    int t=INT_MAX;
    for(int k=i+2;k<=j;k++){
        if(c[i]==c[k]){
            t=min(t,dp(i+1,k-1)+dp(k+1,j));
           // if(i==2&&j==6)
        //        cout<<"t "<<t<<" "<<k<<" "<<dp(i+1,k-1)<<"\n";
        }
    }
    tans=min(tans,t);
    if(c[i]==c[i+1])
        tans=min(tans,1+dp(i+2,j));
 //   cout<<i<<" "<<j<<" "<<tans<<"\n";
    return d[i][j]=tans;
}

int main(){
    memset(d,-1,sizeof(d));
   cin>>n;
   for(int i=1;i<=n;i++)
        cin>>c[i];
   cout<<dp(1,n)<<"\n";
   return 0;
}
