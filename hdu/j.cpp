#include<bits/stdc++.h>
using namespace std;

int cnt1[10];
int cnt2[10];
int cnt[10];

int main() {
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    memset(cnt,0,sizeof(cnt));
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        cnt1[x]++;
        cnt[x]++;
    }
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        cnt2[x]++;
        cnt[x]++;
    }
    bool flag=true;
    for(int i=1; i<=5; i++) {
        if(cnt[i]%2!=0) {
            flag=false;
            break;
        }
    }
    if(!flag) {
        cout<<"-1\n";
        return 0;
    }
    int ans1=0;
    int ans2=0;
    int ans=0;
    for(int i=0; i<=5; i++) {
        if(cnt1[i]>cnt2[i]) {
            ans1+=cnt1[i]-cnt2[i];
        } else if(cnt1[i]<cnt2[i])
            ans2+=cnt2[i]-cnt1[i];
    }
    if(ans1!=ans2) {
        cout<<"-1\n";
        return 0;
    }
    ans=ans1/2;
    cout<<ans<<"\n";
    return 0;
}


