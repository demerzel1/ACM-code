#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char s[maxn];
char ans[maxn];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    char c=s[len-1];
    int k=len-1;
    ans[k]=c;
    k--;
    for(int i=len-2;i>=0;i--){
        if(s[i]>=c){
            ans[k]=s[i];
            c=s[i];
            k--;
        }
    }
    for(int i=k+1;i<=len-1;i++){
        printf("%c",ans[i]);
    }
    return 0;
}
