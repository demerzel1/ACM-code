#include<bits/stdc++.h>
using namespace std;

long long twopower[100000];
int a[100005];

int init(){
    twopower[0]=1;
    int i;
    for(i=1;twopower[i-1]<=3*1e9;i++)
        twopower[i]=twopower[i-1]*2;
    return i;
}

int N;
map<int,int> mp;

int main(){
    int n=init();
    long long int cnt=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        a[i]=x;
        mp[x]++;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<N;j++){
            if(a[j]+a[j]==twopower[i]){
                cnt+=mp[a[j]]-1;
         //       printf("%d ",cnt);
            }
            else{
                cnt+=mp[twopower[i]-a[j]];
             //   printf("%d ",cnt);
            }
        }
    }
 //   printf("\n");
    cout<<cnt/2;
    return 0;

}
