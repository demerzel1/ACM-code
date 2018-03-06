#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[205];
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int ans=0;
    for(int i=0;i<n;i++){
        int cntu=0,cntr=0,cntd=0,cntl=0;
        for(int j=i;j<n;j++){
            if(s[j]=='U')   cntu++;
            if(s[j]=='R')   cntr++;
            if(s[j]=='D')   cntd++;
            if(s[j]=='L')   cntl++;
            if(cntu==cntd&&cntr==cntl){
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
