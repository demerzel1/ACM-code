#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn];
int minx=INT_MAX;
int x,y;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(i==0)
            scanf("%d",&a[i]);
        else{
            scanf("%d",&a[i]);
            if(minx>fabs(a[i]-a[i-1])){
                minx=fabs(a[i]-a[i-1]);
                x=i;
                y=i-1;
            }
        }
    }
    if(minx>fabs(a[n-1]-a[0])){
        minx=fabs(a[n-1]-a[0]);
        x=0;
        y=n-1;
    }
    printf("%d %d",x+1,y+1);
    return 0;
}
