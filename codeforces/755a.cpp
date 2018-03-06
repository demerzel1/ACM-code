#include<bits/stdc++.h>
using namespace std;

#define Max 1000000
bool prime[Max];
void IsPrime(){
     prime[0]=prime[1]=0;prime[2]=1;
     for(int i=3;i<Max;i++)
        prime[i]=i%2==0?0:1;
     int t=(int)sqrt(Max*1.0);
     for(int i=3;i<=t;i++)
       if(prime[i])
         for(int j=i*i;j<Max;j+=2*i)//ÓÅ»¯
            prime[j]=0;
}

int main(){
    IsPrime();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=1000;i++){
        if(!prime[n*i+1]){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
