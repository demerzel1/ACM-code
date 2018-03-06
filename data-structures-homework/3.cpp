#include<bits/stdc++.h>
using namespace std;
int x[300005];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i];
    sort(x,x+n);
    int ans=x[(n+1)/2-1];
    cout<<ans<<endl;
    return 0;
}
