#include<bits/stdc++.h>
using namespace std;

char str[505];
int C;
int w[55];
int n;
void getc(){
    n=0;
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]==' '){
            n++;
        }
        else{
            w[n]=w[n]*32+(str[i]-'a'+1);
        }
    }
}
int judge(){
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(w[i]==0||w[j]==0)
                continue;
            if((C/w[i])%(n+1)==(C/w[j])%(n+1)){
                C=min((C/w[i]+1)*w[i],(C/w[j]+1)*w[j]);
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    while(gets(str)!=NULL){
        memset(w,0,sizeof(w));
        getc();
        C=100000000;
        for(int i=0;i<=n;i++){
            if(C>w[i])
                C=w[i];
        }
        while(judge()==0);
        printf("%s\n",str);
        printf("%d\n\n",C);
    }
    return 0;
}
