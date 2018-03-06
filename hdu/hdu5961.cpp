#include<bits/stdc++.h>
using namespace std;
#define maxn 2020
bool mp1[maxn][maxn];
bool mp2[maxn][maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(mp1,false,sizeof(mp1));
        memset(mp2,false,sizeof(mp2));
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<n;j++){
                if(s[j]=='P')
                    mp1[i][j]=true;
                if(s[j]=='Q')
                    mp2[i][j]=true;
            }
        }

    }
}
