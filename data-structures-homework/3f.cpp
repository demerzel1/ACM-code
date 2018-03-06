#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#define Max 100001
using namespace std;

int main(){
    int N,n,m;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&n,&m);
        int house[m],l,u,k,start,need;
        for(int i=0;i<m;i++)
            scanf("%d",&house[i]);
        sort(house,house+m);
        l=0;
        u=(house[m-1]-house[0]+1)*2;
        while(u>l){
            k=(u+l)/2;
            start=house[0];
            need=1;
            for(int i=1;i<m;i++){
                if(house[i]>start+k){
                    start=house[i];
                    need++;
                }
            }
            if(need>n)
                l=k+1;
            else
                u=k;
        }
        printf("%.1f\n",(double)u/(double)2);
    }
    return 0;
}
