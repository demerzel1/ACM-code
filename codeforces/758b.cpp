#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;
int r,b,y,g;
int cnt[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>str;
    int l=str.size();
    for(int i=0;i<l;i++){
        if(str[i]=='R')
            r=i%4;
        if(str[i]=='B')
            b=i%4;
        if(str[i]=='Y')
            y=i%4;
        if(str[i]=='G')
            g=i%4;
        if(str[i]=='!')
            cnt[i%4]++;
    }
  //  cout<<g<<"\n";
    cout<<cnt[r]<<" "<<cnt[b]<<" "<<cnt[y]<<" "<<cnt[g]<<"\n";
    return 0;
}
