#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int s[30001];
int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    for(;i<n;i++){
        int N;
        int sum=0;
        scanf("%d",&N);
        int j;
        int rn=N;
        int x;
        for(j=0;j<N;j++)
            scanf("%d",&s[j]);
        sort(s,s+N);
        if(N%2!=0){
            if(N==1)
                x=N;
            else
                x=N/2+1;
        }
        else{
            N--;
            if(N==1)
                x=N;
            else
                x=N/2+1;
        }
        x--;
     //   cout<<x<<endl;
        for(j=0;j<rn;j++){
          //      cout<<s[x]<<" "<<s[j]<<endl;
            sum+=abs(s[x]-s[j]);
        }
        cout<<sum<<endl;
    }
    return 0;
}
