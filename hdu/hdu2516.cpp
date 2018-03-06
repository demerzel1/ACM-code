#include<bits/stdc++.h>
using namespace std;

int f[50];
map<int,int> mp;
int main(){
    f[0]=2;
    f[1]=3;
    mp[2]=1;
    mp[3]=1;
    for(int i=2;i<50;i++){
        f[i]=f[i-1]+f[i-2];
        mp[f[i]]=1;
    }
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        if(mp[n]==1)
            printf("Second win\n");
        else
            printf("First win\n");
    }
    return 0;
}
