#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
vector<string> vstr1,vstr2,ans;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    while(true) {
        vstr1.clear();
        vstr2.clear();
        ans.clear();
        int lv1=0;
        int lv2=0;
        while(true) {
            string str;
            str.resize(35);
            if(scanf("%s",&str[0])==EOF) {
                return 0;
            }
            if(str[0]=='#'&&str[1]=='\0')
                break;
            vstr1.push_back(str);
            lv1++;
            //     cout<<str<<str.length()<<endl;
        }
        //  printf("%d\n",lv1);
        while(true) {
            string str;
            str.resize(35);
            scanf("%s",&str[0]);
            if(str[0]=='#'&&str[1]=='\0')
                break;
            vstr2.push_back(str);
            lv2++;
            //      cout<<str<<endl;
        }
        //   cout<<111;
        for(int i=1; i<=lv1; i++) {
            for(int j=1; j<=lv2; j++) {
                if(vstr1[i-1]==vstr2[j-1]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                } else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //  cout<<111<<endl;
        int i=lv1;
        int j=lv2;
        int cnt=0;
        //   printf("i=%d j=%d\n",i,j);
        while(i>0&&j>0) {
            //       printf("i=%d j=%d\n",i,j);
            if(vstr1[i-1]==vstr2[j-1]) {
                //     cout<<"flksajf"<<endl;
                cnt++;
                ans.push_back(vstr1[i-1]);
                i--,j--;
            } else if(vstr1[i-1]!=vstr2[j-1]) {

                if(dp[i][j-1]>dp[i-1][j])
                    j--;
                else
                    i--;
            }
        }
        //     cout<<111;
        //     printf("\ncnt %d\n",cnt);
        for(int i=cnt-1; i>=0; i--) {
            for(int j=0; ans[i][j]!='\0'; j++)
                printf("%c",ans[i][j]);
//       cout<<ans[i];
            if(i!=0)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
