#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int num[1001];
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF){
            int count=0;
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++){
            int sw;
            if(num[j]>num[j+1]){
                sw=num[j];
                num[j]=num[j+1];
                num[j+1]=sw;
                count++;
            }
        }
        printf("Minimum exchange operations : %d\n",count);
    }
    return 0;
}
