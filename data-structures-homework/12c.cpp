#include<bits/stdc++.h>
using namespace std;
int flag[27],gra[27][27],getin[27];
void dfs(int cnt,char* str,int len){
    for(int i=0;i<26;i++){
        if(!getin[i]&&flag[i]){
            str[cnt]=i+'a';
            if(cnt==len-1){
                str[cnt+1]='\0';
                printf("%s\n",str);
                continue;
            }
            for(int j=0;j<26;j++)
                if(gra[i][j]) getin[j]--;
            flag[i]=0;
            dfs(cnt+1,str,len);
            flag[i]=1;
            for(int j=0;j<26;j++){
                if(gra[i][j]) getin[j]++;
            }
        }
    }
}

int main(){
    char strv[200];
    int v=0;
    while(gets(strv)!=NULL){
        if(!v) v=1;
        else printf("\n");
        memset(flag,0,sizeof(flag));
        memset(gra,0,sizeof(gra));
        memset(getin,0,sizeof(getin));
        int length=strlen(strv);
        for(int i=0;i<length;i++){
            if(strv[i]!=' ')
                flag[strv[i]-'a']=1;
        }
        gets(strv);
        int len=strlen(strv);
        int temp;
        for(int i=0;i<len;i++){
            if(strv[i]==' ') continue;
            if((i+1)%4==1)
                temp=strv[i]-'a';
            else if((i-1)%4==1){
                gra[temp][strv[i]-'a']=1;
                getin[strv[i]-'a']++;
            }
        }
        dfs(0,strv,(length+1)/2);
    }
    return 0;
}
