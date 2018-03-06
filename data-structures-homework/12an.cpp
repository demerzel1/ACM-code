#include<bits/stdc++.h>
using namespace std;
char ara[5000][30];

int main(){
    int k,j,i,f,p;
    int aral[30]={0};
    for(k=0;;k++){
        scanf("%s",ara[k]);
        if(ara[k][0]=='#'){
            break;
        }
    }
    for(j=0;;j++){
        for(i=0,f=0;i<k;i++){
            if(ara[i][j]=='\0')
                ara[i][j+1]='\0';
            else{
                f=1;
                p=ara[i][j]-'A';
                if(aral[p]==0){
                    printf("%c",ara[i][j]);
                    aral[p]=1;
                }
            }
        }
        if(f==0)
            break;
    }
    printf("\n");
    return 0;
}
