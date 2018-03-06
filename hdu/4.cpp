#include<bits/stdc++.h>
using namespace std;
#define maxn 25
using ll=long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    int n,m;
    int num[maxn];
    while(T--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        sort(num,num+n);
        int i=0;
        int j=0;
        ll ans=1;
        int a,b;
         while(m){
            a=num[i]*num[i+1];
            b=num[n-j-1]*num[n-j-2];
            if(a>=b &&m>=2) {
                ans*=a;
                i+=2;
                m-=2;
            } else {
                ans*=num[n-j-1];
                j++;
                m--;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
