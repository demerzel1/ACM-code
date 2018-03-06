#include<bits/stdc++.h>
using namespace std;
#define maxn 105

int a[maxn][maxn];
int s[maxn][maxn];
int n,m;
int ans;

int main(){
    while(cin>>n>>m&&(n||m)){
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        int x;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>x;
                if(x==0)
                    a[i][j]=1;
                else
                    a[i][j]=-1000;
                s[i][j]=s[i-1][j]+a[i][j];
            }
        ans=0;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int t=0;
                for(int k=1;k<=m;k++){
                    if(t<0)
                        t=s[j][k]-s[i][k];
                    else
                        t+=s[j][k]-s[i][k];
                    ans=max(ans,t);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
