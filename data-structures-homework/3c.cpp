#include<cstdio>
#include<iostream>
#include<cmath>

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
         for(int j=i*i;j<Max;j+=2*i)
            prime[j]=0;
}
int main(){
    IsPrime();
    int N;
    scanf("%d",&N);
    while(N--){
        int c=0;
       long long l,h;
        cin>>l>>h;
        long long i;
        for(i=0;i<sqrt(h);i++){
            if(prime[i]==1){
                long long t;
                for(t=i*i;t<=h;t*=i){
                	if(t>=l&&t<=h)
                		c++;
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
