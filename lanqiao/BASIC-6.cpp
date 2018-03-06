#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int num[35][35];
int main(){
    memset(num,0,sizeof(num));
    int n;
    scanf("%d",&n);
    num[0][0]=1;
    num[1][0]=1;
    num[1][1]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(j==0||j==i){
                num[i][j]=1;
            }
            else{
                num[i][j]=num[i-1][j-1]+num[i-1][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}


