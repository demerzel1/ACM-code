#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
char str[maxn];
int cnt[10];
int main() {
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0; i<len; i++) {
        if(str[i]=='B')         cnt[0]++;
        else if(str[i]=='u')    cnt[1]++;
        else if(str[i]=='l')    cnt[2]++;
        else if(str[i]=='b')    cnt[3]++;
        else if(str[i]=='a')    cnt[4]++;
        else if(str[i]=='s')    cnt[5]++;
        else if(str[i]=='r')    cnt[6]++;
    }
    int ans=INT_MAX;
    for(int i=0; i<7; i++) {
        if(i==0||i==2||i==5||i==6||i==3) {
            ans=min(ans,cnt[i]);
        } else {
            ans=min(ans,cnt[i]/2);
        }
    }
    printf("%d\n",ans);
    return 0;
}
