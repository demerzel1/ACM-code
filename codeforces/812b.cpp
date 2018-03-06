#include<bits/stdc++.h>
using namespace std;

string mp[20];
int rht[20];
int lft[20];

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>mp[i];
    int ans=0;
    for(int i=0; i<n; i++) {
        int tlft=105;
        int trht=-1;
        for(int j=0; j<m+2; j++) {
            if(mp[i][j]=='1') {
                trht=max(trht,j);
                tlft=min(tlft,j);
            }
        }
        rht[i]=trht;
        lft[i]=tlft;
      //  cout<<trht<<" "<<tlft<<"\n";
    }
    int lr=0;
    for(int i=n-1; i>=1; i--) {
        if(!lr) {
            ans+=rht[i];
            if(rht[i-1]+rht[i]<(m+1-lft[i-1])+m+1-rht[i]) {
                ans+=rht[i];
                ans++;
            } else {
                ans+=m+1-rht[i];
                ans++;
                lr=1;
            }
        } else {
            ans+=m+1-lft[i];
            if(rht[i-1]+lft[i]<(m+1-lft[i-1])+m+1-lft[i]) {
                ans+=lft[i];
                ans++;
                lr=0;
            } else {
                ans+=m+1-lft[i];
                ans++;
                lr=1;
            }
        }
      //  cout<<ans<<"\n";
    }
    if(!lr) {
        ans+=rht[0];
    } else
        ans+=m+1-lft[0];
    cout<<ans<<"\n";
    return 0;
}
