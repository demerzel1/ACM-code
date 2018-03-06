#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n;
double p[maxn];
double l[maxn];
double ans[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++){
        l[i]=(l[i-1]+1)*p[i];
    }
    for(int i=1;i<=n;i++){
        ans[i]=ans[i-1]+p[i]*(2*l[i-1]+1);
    }
    cout<<fixed<<setprecision(15)<<ans[n];
    return 0;
}
