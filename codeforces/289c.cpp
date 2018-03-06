#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==1&&k==1){
        printf("a");
    }
    else if(k==1){
        printf("-1");
    }
    else if(k>n){
        printf("-1");
    }
    else if(k==n){
        for(int i=0;i<n;i++){
            printf("%c",'a'+i);
        }
    }
    else if(k<n&&k>=2){
        int num=n-(k-2);
        bool change=true;
        for(int i=0;i<num;i++){
            if(change){
                putchar('a');
                change=false;
            }
            else if(!change){
                putchar('b');
                change=true;
            }
        }
        for(int i=0;i<k-2;i++){
            putchar('c'+i);
        }
    }
    return 0;
}
