#include<bits/stdc++.h>
using namespace std;
#define maxn 2005

int n;
int a[maxn];
int ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=abs(a[i]);
    }
    for(int i=1;i<=n;i++){
        int na=0;
        int nb=0;
        for(int j=1;j<i;j++){
            if(a[j]<a[i])
                na++;
        }
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i])
                nb++;
        }
        ans+=min(na,nb);
    }
    cout<<ans;
    return 0;
}
