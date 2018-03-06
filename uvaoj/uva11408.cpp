#include<bits/stdc++.h>
using namespace std;
#define Max 5000005
bool prime[Max];
vector<int> num;
void IsPrime() {
    prime[0]=prime[1]=0;
    prime[2]=1;
    for(int i=3; i<Max; i++)
        prime[i]=i%2==0?0:1;
    int t=(int)sqrt(Max*1.0);
    for(int i=3; i<=t; i++)
        if(prime[i])
            for(int j=i*i; j<Max; j+=2*i) //§ã§Ö¨m¨b
                prime[j]=0;
    num.push_back(2);
    for(int i=3; i<Max; i+=2) {
        if(prime[i])
            num.push_back(i);
    }
}
int ans[Max];
void calculate() {
    int l=num.size();
    for(int i=1; i<=Max; i++) {
        int sum=0;
        int x=i;
        //  printf("%d\n",i);
        for(int j=0; j<l&&x!=1&&num[j]*num[j]<=x; j++) {
            if(x%num[j]==0) {
                sum+=num[j];
       //         if(i==10) printf("%d ",num[j]);
                while(x%num[j]==0)
                    x/=num[j];
            }
        }
        if(x>1)
            sum+=x;
        //   printf("%d\n",sum);
    //    if(i<=120&&prime[sum]) printf("%d ",i);
        if(prime[sum])
            ans[i]=ans[i-1]+1;
        else
            ans[i]=ans[i-1];
    }
    return;
}

int main() {
    IsPrime();
    calculate();
    int a,b;
    while(scanf("%d",&a)&&a) {
        scanf("%d",&b);
        printf("%d\n",ans[b]-ans[a-1]);
    }
    return 0;
}
