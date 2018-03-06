#include<bits/stdc++.h>
using namespace std;
#define maxn 105

int tans[maxn];
int t[maxn];
int ans;
int b,d;
string a,c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>b>>d;
    cin>>a>>c;
    int sa=a.length();
    int sc=c.length();
    for(int i=0;i<sc;i++){
        int index=i;
        for(int j=0;j<sa;j++){
            if(a[j]==c[index]){
                index++;
                if(index==sc){
                    tans[i]++;
                    index=0;
                }
            }
        }
        t[i]=index;
    }
    int index=0;
    for(int i=0;i<b;i++){
        ans+=tans[index];
        index=t[index];
    }
  //  cout<<"ans="<<ans<<"\n";
    ans/=d;
    cout<<ans<<"\n";
    return 0;
}
