#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int num[10005];
int main(){
    int n;
    scanf("%d",&n);
    int p=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int a;
    scanf("%d",&a);
    for(int i=0;i<n;i++){
        if(a==num[i]){
            p=i+1;
            break;
        }
    }
    printf("%d",p);
    return 0;
}



