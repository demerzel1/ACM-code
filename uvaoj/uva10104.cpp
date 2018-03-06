#include<bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

int main(){
    int a,b,x,y;
    int ans;
    while(cin>>a>>b){
        ans=exgcd(a,b,x,y);
        cout<<x<<" "<<y<<" "<<ans<<"\n";
    }
    return 0;
}
