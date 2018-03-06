#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int n,indmax,indmin;
int num[maxn];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(num[i]>num[indmax]){
            indmax=i;
        }
        if(num[i]<=num[indmin]){
            indmin=i;
        }
    }
    int ans=n-indmin-1+indmax;
    if(indmax>indmin)
        ans--;
    cout<<ans<<"\n";
    return 0;
}
