#include<bits/stdc++.h>
using namespace std;
#define Max 100005
bool prime[Max];
void IsPrime(){
    prime[0]=prime[1]=1;
    prime[2]=1;
    for(int i=3; i<Max; i++)
        prime[i]=i%2==0?0:1;
    int t=(int)sqrt(Max*1.0);
    for(int i=3; i<=t; i++)
        if(prime[i])
            for(int j=i*i; j<Max; j+=2*i)
                prime[j]=0;
}
int main(){
    IsPrime();
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1\n1");
        return 0;
    }
    else if(n==2){
            printf("1\n1 1");
            }
    else{
        printf("2\n");
        for(int i=2;i<2+n;i++){
            if(prime[i])
                printf("1 ");
            else
                printf("2 ");
        }
    }
    return 0;
}
