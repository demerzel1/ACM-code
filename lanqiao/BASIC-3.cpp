#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int p=abs(i-j);
            printf("%c",65+p);
        }
        printf("\n");
    }
    return 0;
}

