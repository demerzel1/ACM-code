#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int N,L;
int train[55];
int cas=0;

int sw(){
    for(int i=0;i<L;i++)
        for(int j=0;j<L-i-1;j++){
        if(train[j]>train[j+1]){
            int t;
            t=train[j];
            train[j]=train[j+1];
            train[j+1]=t;
            cas++;
        }
    }
}
int main(){
    scanf("%d",&N);
    while(N--){
        scanf("%d",&L);
        memset(train,0,sizeof(train));
        for(int i=0;i<L;i++){
            scanf("%d",&train[i]);
        }
        sw();
        printf("Optimal train swapping takes %d swaps.\n",cas);
        cas=0;
    }
    return 0;
}
