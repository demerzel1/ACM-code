#include<bits/stdc++.h>
using namespace std;
#define Max 1000005
bool vis[Max];
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
        memset(vis,false,sizeof(vis));
        int i;
        int cnt=0;
        for(i=1;i<n;i++){
            if(!vis[i]&&prime[i])
            if(!vis[n-i] and prime[n-i]){
        //        printf("%d\n",i);
                vis[i]=true;
                vis[n-i]=true;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
