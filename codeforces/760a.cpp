#include<bits/stdc++.h>
using namespace std;

int main() {
    int m,d;
    scanf("%d%d",&m,&d);
    int cnt=0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        cnt=31;
    else if(m==2)
        cnt=28;
    else
        cnt=30;
    // printf("%d",cnt);
    cnt=cnt-(8-d);
    //  printf("%d",cnt);
    int ans=cnt/7+1;
    if(cnt%7!=0)
        ans++;
    printf("%d",ans);
    return 0;
}
