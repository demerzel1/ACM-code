#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,n;
int ok(int x){
    if(x>=1&&x<=n)
        return 1;
    else return 0;
}
int main(){

    cin>>n>>a>>b>>c>>d;
    int e;
    long long int ans=0;
    for(int i=1;i<=n;i++){
        e=i;
        if(ok(e+a-d)&&ok(e+b-c)&&ok(e+a+b-c-d))
            ans++;
    }
    ans*=n;
    printf("%lld",ans);
    return 0;
}
