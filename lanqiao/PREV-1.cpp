#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int d=__gcd(a,b);
    int e=a*b/d;
    d=__gcd(e,c);
    int ans=e*c/d;
    cout<<ans;
    return 0;
}
