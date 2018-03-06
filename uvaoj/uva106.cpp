#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int gcd(int a,int b){
    if(!a)return 1;if(!b)return a;
    if(a<0) a=-a; for(int t;b;t=a%b,a=b,b=t);
    return a;
}

bool vis[maxn];

int main(){
    int n;
    while(cin>>n){
        memset(vis,false,sizeof(vis));
        int t=(int)sqrt(n);
//        cout<<t<<" t\n";
        int ans=0;
        for(int i=1;i<=t;i++){
            int s=(int)sqrt(n-i*i);
//            cout<<s<<" s\n";
            for(int j=i+1;j<=s;j++){
                int x=2*i*j;
                int y=j*j-i*i;
                int z=i*i+j*j;
//                cout<<x<<' '<<y<<' '<<z<<"\n";
                if(i%2!=j%2&&gcd(i,j)==1){
                    ans++;
                    vis[x]=vis[y]=vis[z]=true;
                }
                for(int k=2;k*z<=n;k++){
                    vis[k*x]=vis[k*y]=vis[k*z]=true;
                }
            }
        }
        int ans1=0;
        for(int i=1;i<=n;i++){
            if(!vis[i])
                ans1++;
        }
        cout<<ans<<" "<<ans1<<"\n";
    }
    return 0;
}
