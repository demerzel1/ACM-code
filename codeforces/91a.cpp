#include <iostream>
using namespace std;

string s1,s2;

bool flag=true;
int ind[10005][30];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s1>>s2;
    int sz1=s1.size();
    int sz2=s2.size();
    for(int j=0;j<26;j++){
        ind[sz1][j]=-1;
    }
    for(int i=sz1-1;i>=0;i--){
        for(int j=0;j<26;j++){
            ind[i][j]=ind[i+1][j];
        }
        ind[i][s1[i]-'a']=i;
    }
    ind[0][s1[0]-'a']=0;
    int pos=0;
    int ans=0;
    for(int i=0;i<sz2;i++){
        int t=s2[i]-'a';
      //  cout<<pos<<endl;
        if(ind[0][t]==-1){
            flag=false;
            break;
        }
        if(ind[pos][t]==-1){
        //    cout<<pos<<endl;
            ans++;
            pos=0;
        }
        pos=ind[pos][t]+1;
    }
    cout << (!flag ? -1 : ans+1) << '\n';
    return 0;
}