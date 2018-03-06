#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
#define maxn 55
int main(){
    int n;
    bool x[maxn],y[maxn];
    memset(x,false,sizeof(x));
    memset(y,false,sizeof(y));
    scanf("%d",&n);
    for(int i=0;i<n*n;i++){
        int h,v;
        scanf("%d%d",&h,&v);
        if(x[h]==false&&y[v]==false){
            x[h]=true;
            y[v]=true;
            printf("%d ",i+1);
        }
    }
    return 0;
}
