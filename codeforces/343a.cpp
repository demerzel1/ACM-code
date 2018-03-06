#include<bits/stdc++.h>
using namespace std;
long long ans=0;
void fun(long long a,long long b){
    if(a>b){
        ans+=a/b;
        a=a-(a/b)*b;
    }
    if(a==0){
        return;
    }
    if(b%a==0){
        ans+=b/a;
        return;
    }else{
        fun(b,a);
    }
}


int main(){
    long long a,b;
    scanf("%I64d%I64d",&a,&b);
    fun(a,b);
    cout<<ans<<endl;
    return 0;
}
