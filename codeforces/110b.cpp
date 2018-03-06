#include<bits/stdc++.h>
int main(){
    int n;
    scanf("%d",&n);
    int x=n/4;
    for(int i=0;i<x;i++)
        printf("abcd");
    x=n%4;
    for(int i=0;i<x;i++)
        printf("%c",'a'+i);
    return 0;
}
