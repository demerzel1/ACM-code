#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    n=n%6;
    for(int i=n;i>0;i--){
        if(i%2==0){
            if(x==2)
                x=1;
            else if(x==1)
                x=2;
            }else{
                if(x==0)
                    x=1;
                else if(x==1)
                    x=0;
            }
    }
    printf("%d",x);
    return 0;
}
