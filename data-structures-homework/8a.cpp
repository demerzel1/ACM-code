#include<cstdio>
#include<iostream>
#define Max 15005
using namespace std;
int x[Max],y[Max],hash[Max],n,a[33000];

int main(){
    int i,j,s;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            s=0;
            for(j=0;j<=x[i];j++)
                s+=a[j];
            a[x[i]]++;
            hash[s]++;
        }
        for(i=0;i<n;i++)
            printf("%d\n",hash[i]);
    }
    return 0;
}
