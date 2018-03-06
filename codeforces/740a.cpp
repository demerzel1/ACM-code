#include<bits/stdc++.h>
using namespace std;
#define INF 100000000000
long long ans=INF;
long long n,a,b,c;

void dfs(long long num,long long cost){
    if(num%4==0){
        ans=min(ans,cost);
    //    cout<<ans<<endl;
    }
    if(num>3*n)
        return;
    dfs(num+1,cost+a);
    dfs(num+2,cost+b);
    dfs(num+3,cost+c);
}

int main(){
    cin>>n>>a>>b>>c;
    n=n%4;
    dfs(n,0);
    cout<<ans;
    return 0;
}
