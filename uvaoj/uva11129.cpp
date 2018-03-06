#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int n;
int t[maxn];
int ans[maxn];
int ind;

void solve(int l,int r){
    if(r-l<2)
        return;
    ind=l;
    for(int i=l;i<=r;i+=2){
        t[ind++]=ans[i];
    }
    for(int i=l+1;i<=r;i+=2){
        t[ind++]=ans[i];
    }
    for(int i=l;i<=r;i++){
        ans[i]=t[i];
    }
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid,r);
    return;
}

int main(){
    while(cin>>n&&n){
        for(int i=0;i<n;i++)
            ans[i]=i;
        solve(0,n-1);
        cout<<n<<":";
        for(int i=0;i<n;i++){
            cout<<" "<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}
