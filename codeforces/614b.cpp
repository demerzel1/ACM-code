#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

char str[maxn];
char unbeautiful[maxn];
bool isBeautiful() {
    if(str[0]=='1'&&strlen(str)==1)
        return true;
    for(int i=1; i<strlen(str); i++)
        if(str[i]!='0')
            return false;
    return true;
}
int main() {
    int cnt0=0;
    int n;
    scanf("%d",&n);
    bool flag0=false;
    bool flag1=true;
    while(n--) {
            memset(str,0,sizeof(str));
        scanf("%s",str);
        int len=strlen(str);
        if(str[0]=='0'&&len==1){
            flag0=true;
            continue;
        }
        else if(str[0]=='1'&&isBeautiful()){
            cnt0+=len-1;
            continue;
        }
        else{
            flag1=false;
            strcpy(unbeautiful,str);
        }
    }
    if(flag0){
        printf("0");
    }
    else if(flag1){
        printf("1");
        for(int i=0;i<cnt0;i++)
            printf("0");
    }
    else{
        printf("%s",unbeautiful);
        for(int i=0;i<cnt0;i++)
            printf("0");
    }
    return 0;
}
