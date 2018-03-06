#include<cstdio>
#include<iostream>
#include<algorithm>

int main(){
    int n,num[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int mx=num[0],mn=num[0];
    for(int i=0;i<n;i++){
        if(num[i]>mx)
            mx=num[i];
        if(num[i]<mn)
            mn=num[i];
    }
    printf("%d %d",mn,mx);
    return 0;
}
