#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
int num[2000001];
int f(char str[]){
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len;i++){
        ans*=10;
        if(str[i]>='a'&&str[i]<='c')
            ans+=2;
        if(str[i]>='d'&&str[i]<='f')
            ans+=3;
        if(str[i]>='g'&&str[i]<='i')
            ans+=4;
        if(str[i]>='j'&&str[i]<='l')
            ans+=5;
        if(str[i]>='m'&&str[i]<='o')
            ans+=6;
        if(str[i]>='p'&&str[i]<='s')
            ans+=7;
        if(str[i]>='t'&&str[i]<='v')
            ans+=8;
        if(str[i]>='w'&&str[i]<='z')
            ans+=9;

    }
    return ans;
}
int a[10000];
char str[20];
int main(){
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        while(m--){
            scanf("%s",&str);
            num[f(str)]++;
        }
        for(int i=0;i<n;i++)
          printf("%d\n",num[a[i]]);
    }
    return 0;
}
