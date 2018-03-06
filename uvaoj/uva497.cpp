#include<bits/stdc++.h>
#include<string>
using namespace std;
#define maxn 10005
int num[maxn];
int dp[maxn];
int fro[maxn];


int main(){
    int n;
    while(cin>>n){
        getchar();
        getchar();
        while(n--){
          //  cout<<111<<"\n";
            string s;
            int ind=0;
            while(getline(cin,s)&&s[0]){
          //      cout<<s<<"  s  \n";
                num[ind++]=atoi(s.c_str());
            //    cout<<num[ind-1]<<"\n";
            }
            for(int i=0;i<ind;i++){
                dp[i]=1;
                fro[i]=i;
                for(int j=0;j<i+1;j++){
                    if(num[i]>num[j]&&dp[i]<dp[j]+1) {
                        dp[i]=dp[j]+1;
                        fro[i]=j;
                    }
                }
            }
            int indmax=0;
            int ans=0;
            for(int i=0;i<ind;i++){
                if(ans<dp[i]){
                    ans=dp[i];
                    indmax=i;
                }
            }
            int tans[maxn];
            int tind=1;
            tans[0]=num[indmax];
            while(true){
                if(fro[indmax]==indmax)
                    break;
           //     printf("indmax=%d fro[ind]=%d\n",indmax,fro[indmax]);
                tans[tind]=num[fro[indmax]];
                indmax=fro[indmax];
                tind++;
            }
            cout<<"Max hits: "<<tind<<"\n";
            for(int i=tind-1;i>=0;i--)
                cout<<tans[i]<<"\n";
            if(n)
                cout<<"\n";
        }
    }
    return 0;
}
