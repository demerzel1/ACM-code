#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int cnt=0;
    while(x>0&&y>0){
        if(x==1&&y==1){
            break;
        }
        if(x>y){
            x-=2;
            y+=1;
        }
        else{
            y-=2;
            x+=1;
        }
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
