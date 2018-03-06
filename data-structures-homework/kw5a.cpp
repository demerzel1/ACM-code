#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    long long int ml=max(l1,l2);
    long long int mr=min(r1,r2);
    if(ml<=mr) {
        long long int ans=mr-ml+1;
        if(k>=ml&&k<=mr) {
            ans--;
        }
        cout<<ans;
    } else {
        cout<<0;
    }
    return 0;
}
