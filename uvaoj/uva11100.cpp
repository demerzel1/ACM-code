#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int a[maxn];
int main(){
    int n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int ans=0;
        int t=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                t++;
                ans=max(ans,t);
            }else{
                ans=max(ans,t);
                t=1;
            }
        }
        cout<<ans<<"\n";
        for(int i=0;i<ans;i++){
            for(int j=i;j<n;j+=ans){
                if(j!=i)
                    cout<<" ";
                cout<<a[j];
            }
            cout<<"\n";
        }
    cout<<"\n";
    }
    return 0;
}
