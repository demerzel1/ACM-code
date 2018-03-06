#include<bits/stdc++.h>
using namespace std;
#define Max 1000005
bool vis[Max];
bool prime[Max];
int num[Max];
char str[20];
bool sel[Max];

void IsPrime() {
    prime[0]=prime[1]=0;
    prime[2]=1;
    for(int i=3; i<Max; i++)
        prime[i]=i%2==0?0:1;
    int t=(int)sqrt(Max*1.0);
    for(int i=3; i<=t; i++)
        if(prime[i])
            for(int j=i*i; j<Max; j+=2*i)
                prime[j]=0;
}

void calculate() {
    for(int i=0; i<Max; i++) {
        if(prime[i]) {
            bool flag=true;
            sprintf(str,"%d",i);
            int l=strlen(str);
            for(int j=0; j<l; j++) {
                //   if(i==101) printf("j=%d\n",j);
                int f=0,s=0;
                for(int k=0; k<j; k++)
                    f=f*10+str[k]-'0';
                //   if(i==101) printf("f=%d\n",f);
                for(int k=j; k<l; k++)
                    s=s*10+str[k]-'0';
                //  if(i==101) printf("s=%d\n",s);
                f=s*((int)pow(10,j))+f;
                //      if(i==101) printf("%d ans=%d\n",(int)pow(10,j),f);
                //   printf("aaa%d\n",(int)pow(10,j));
                if(!prime[f]) {
                    flag=false;
                    break;
                }
            }
            if(flag) {
                sel[i]=true;
                //     printf("%d\n",i);
            }
        }
    }
    int cnt=0;
    for(int i=0; i<Max; i++) {
        if(sel[i])
            cnt++;
        num[i]=cnt;
    }
}

int main() {
    IsPrime();
    calculate();
    int a,b;
    while(scanf("%d",&a)&&a!=-1) {
        scanf("%d",&b);
        //    if(a>b)
        //       swap(a,b);
        int ans=num[b]-num[a-1];
        if(ans==0)
            printf("No Circular Primes.\n");
        else if(ans==1)
            printf("1 Circular Prime.\n");
        else
            printf("%d Circular Primes.\n",ans);
    }
    return 0;
}
