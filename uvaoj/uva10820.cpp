#include<bits/stdc++.h>
using namespace std;

#define Max 50005
bool prime[Max];
void IsPrime() {
    prime[0]=prime[1]=0;
    prime[2]=1;
    for(int i=3; i<Max; i++)
        prime[i]=i%2==0?0:1;
    int t=(int)sqrt(Max*1.0);
    for(int i=3; i<=t; i++)
        if(prime[i])
            for(int j=i*i; j<Max; j+=2*i) //ÓÅ»¯
                prime[j]=0;
}
int cnt[Max];
int a=0;
void init() {
    for(int i=0; i<Max-1; i++) {
        if(prime[i])
            a++;
        cnt[i]=a;
    }
}

int main() {
    IsPrime();
    init();
    int n;
    while(scanf("%d",&n)&&n) {

    }
}
