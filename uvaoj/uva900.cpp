#include<bits/stdc++.h>
using namespace std;

long long ans[55];

long long f(int i){
    if(i==1)    return 1;
    if(i==2)    return 2;
    if(ans[i]!=0)   return ans[i];
    else{
        ans[i]=f(i-1)+f(i-2);
        return ans[i];
    }
}

int main(){
    ans[1]=1;
    ans[2]=2;
    f(50);
    int n;
    while(scanf("%d",&n)){
        if(n==0)
            break;
        cout<<ans[n]<<"\n";
    }
    return 0;
}
