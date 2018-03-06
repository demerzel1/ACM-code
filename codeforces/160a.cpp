#include<bits/stdc++.h>
using namespace std;

int n;
int sum;
int a[110];
int tsum;
int ans;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        tsum+=a[i];
        ans++;
        if(tsum>sum/2)
            break;
    }
    cout<<ans;
    return 0;
}
