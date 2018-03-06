#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int a[1000000],p[1000000];
int nbb(int x){
    return x&(-x);
}
int nyy(int x){
    int ans=1;
    while(x>0){
        ans+=a[x];
        x-=nbb(x);
    }
    return ans;
}

int main(){
    int i,n,x,c,y;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        x++;
        p[nyy(x)]++;
        c=x;
        while(c<=100000){
            a[c]++;
            c+=nbb(c);
        }
    }
    for(i=1;i<=n;i++)
        printf("%d\n",p[i]);
    return 0;
}
