#include<bits/stdc++.h>
using namespace std;
#define Max 1000005
bool prime[Max];
void IsPrime(){
     prime[0]=prime[1]=0;prime[2]=1;
     for(int i=3;i<Max;i++)
        prime[i]=i%2==0?0:1;
     int t=(int)sqrt(Max*1.0);
     for(int i=3;i<=t;i++)
       if(prime[i])
         for(int j=i*i;j<Max;j+=2*i)
            prime[j]=0;
}

int main(){
    IsPrime();
    int n;
    while(scanf("%d",&n)&&n){
        int i;
        for(i=2;i<n;i++){
            if(prime[i]){
                if(prime[n-i]){
                    printf("%d = %d + %d\n",n,i,n-i);
                    break;
                }
            }
        }
        if(i>=n){
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
