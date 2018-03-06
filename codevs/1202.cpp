#include<cstdio>
#include<iostream>
#include<algorithm>

int main(){
    int n;
    int num[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    int s=0;
    for(int i=0;i<n;i++)
        s+=num[i];
    printf("%d",s);
    return 0;
}
