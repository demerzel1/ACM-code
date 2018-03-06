#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int cas=0;
    while(cin>>n>>m){
        char s[30];
        cas++;
        cout<<"Case "<<cas<<"\n";
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                s[j]='A'+i-j;
            }
            for(int j=i;j<m;j++){
                s[j]='A'+j-i;
            }
            for(int j=0;j<m;j++)
                printf("%c",s[j]);
            printf("\n");
        }
    }
    return 0;
}
