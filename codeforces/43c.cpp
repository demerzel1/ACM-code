#include<bits/stdc++.h>
using namespace std;

int cnt1,cnt2,cnt3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%3==0)
            cnt3++;
        if(a%3==1)
            cnt1++;
        if(a%3==2)
            cnt2++;
    }
    int ans=cnt3/2+min(cnt1,cnt2);
    cout<<ans;
    return 0;
}

