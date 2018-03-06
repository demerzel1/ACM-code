#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int letter[26]={0};
    int n;
    scanf("%d",&n);
    getchar();
    for(int j=0;j<n;j++){
        char str[100];
        gets(str);
        int i;
        for(i=0;str[i]!='\0';i++){
            if(str[i]>=65&&str[i]<=90)
                letter[str[i]-65]++;
            if(str[i]>=97&&str[i]<=122)
               letter[str[i]-97]++;
        }
    }
    int i;
    int m=letter[0];
    for(i=25;i>=0;i--){
        if(letter[i]>m)
            m=letter[i];
    }
   for(;m>0;m--)
    for(i=0;i<26;i++){
            if(letter[i]==m)
            printf("%c %d\n",i+65,letter[i]);
    }
    return 0;
}
