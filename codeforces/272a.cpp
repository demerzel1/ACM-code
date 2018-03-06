#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum=0;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
    }
    n++;
    int ans=0;
    for(int i=1;i<=5;i++)
        if((sum+i)%n!=1)
            ans++;
    cout<<ans<<"\n";
    return 0;
}
