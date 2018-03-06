#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];
int yuchu[maxn];
int yuchu1[maxn];
int gcd(int a,int b){
    if(!a)return 1;if(!b)return a;
    if(a<0) a=-a; for(int t;b;t=a%b,a=b,b=t);
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        yuchu[1]=a[1];
        yuchu1[n]=a[n];
        for(int i=2;i<=n;i++){
            yuchu[i]=gcd(yuchu[i-1],a[i]);
        }
        for(int i=n-1;i>=1;i--)
            yuchu1[i]=gcd(yuchu1[i+1],a[i]);
        int ans=max(yuchu[n-1],yuchu1[2]);
        for(int i=1;i<=n;i++){
            ans=max(ans,gcd(yuchu[i-1],yuchu1[i+1]));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
