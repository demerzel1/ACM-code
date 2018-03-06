#include<bits/stdc++.h>
using namespace std;


int solve(int n){
    int ans=n/5;
    for(int i=25;;i*=5){
        if(i>n)
            break;
        ans+=n/i;
    }
    return ans;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",solve(n));
    }
    return 0;
}
