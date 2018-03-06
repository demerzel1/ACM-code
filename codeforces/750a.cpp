#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int t=240-k;
    int i;
    for(i=1;i<=n;i++){
        if(i*5>t){
            break;
        }else{
        t-=i*5;
        }
    }
    printf("%d",i-1);
    return 0;
}
