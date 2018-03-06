#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int num[maxn];
int cnt[2];
int ans;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(num[i]==1)
            ans++;
    }
    if(ans==n){
        cout<<n-1<<"\n";
        return 0;
    }
    int tans=ans;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cnt[0]=cnt[1]=0;
            for(int k=i;k<=j;k++){
                cnt[num[k]]++;
            }
            if(cnt[0]>cnt[1])
                ans=max(ans,tans+cnt[0]-cnt[1]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
