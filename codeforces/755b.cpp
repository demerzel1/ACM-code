#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>s;
        mp[s]++;
    }
    for(int i=0;i<m;i++){
        cin>>s;
        mp[s]++;
        if(mp[s]>1){
            cnt++;
        }
    }
    n=n-cnt+(cnt-(cnt/2));
    m=m-cnt+cnt/2;
  //  cout<<n<<" "<<m<<endl;
    if(n>m){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}

