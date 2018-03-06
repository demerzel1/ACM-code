#include<bits/stdc++.h>
using namespace std;
int x[200005];
int y[200005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
   //         if(x[i]==x[j]&&y[i]==y[j])
   //             continue;
            if(x[i]==x[j]){
       //         printf("x   i=%d j=%d\n",i,j);
                cnt++;
            }
            else if(y[i]==y[j]){
                cnt++;
       //         printf("y   i=%d j=%d\n",i,j);
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
