#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=400000+10;
char s[MAXN];
int next[MAXN],ans[MAXN];

void GetNext(const char* p){
    int j=0;
    next[0]=next[1]=0;
    for(int i=1;p[i];i++){
        while(j&&p[i]!=p[j])
            j=next[j];
        if(p[i]==p[j])
            j++;
        next[i+1]=j;
    }
}
int main(){
    while(~scanf("%s",s)){
        GetNext(s);
        int j=strlen(s),k=0;
        while(j){
            ans[k++]=j;
            j=next[j];
        }
        for(int i=k-1;i>0;i--)
            printf("%d ",ans[i]);
        printf("%d\n",ans[0]);
    }
    return 0;
}
