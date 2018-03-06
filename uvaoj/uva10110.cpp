#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
vector<string> vstr1,vstr2;
int dp[maxn][maxn];

int main(){
    int cnt=0;
    string a,b;
    while(getline(cin,a)){
        cnt++;
        getline(cin,b);
        memset(dp,0,sizeof(dp));
        vstr1.clear();
        vstr2.clear();
        int la=a.length();
        int lb=b.length();
        for(int i=0;i<la;i++){
            if(a[i]<'0'||(a[i]>'9'&&a[i]<'A')||a[i]>'z'||(a[i]>'Z'&&a[i]<'a'))
                a[i]=' ';
        }
        for(int i=0;i<lb;i++){
            if(b[i]<'0'||(b[i]>'9'&&b[i]<'A')||b[i]>'z'||(b[i]>'Z'&&b[i]<'a'))
                b[i]=' ';
        }
        string s;
        stringstream stream(a);
        int cnt1=0,cnt2=0;
        while(stream>>s){
            vstr1.push_back(s);
            cnt1++;
            s.clear();
        }
        stringstream strea(b);
        while(strea>>s){
            vstr2.push_back(s);
            cnt2++;
            s.clear();
        }
        for(int i=1;i<=cnt1;i++){
            for(int j=1;j<=cnt2;j++){
                if(vstr1[i-1]==vstr2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        printf("%2d. ",cnt);
        if(a==""||b==""){
            printf("Blank!\n");
        }else{
            printf("Length of longest match: %d\n",dp[cnt1][cnt2]);
        }
        a.clear();
        b.clear();
    }
    return 0;
}
