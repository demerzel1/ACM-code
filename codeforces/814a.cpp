#include<bits/stdc++.h>
using namespace std;
#define maxn 105

int a[maxn];
int b[maxn];

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++)
        cin>>b[i];
    bool flag=false;
    if(k>=2){
        flag=true;
    }else{
        for(int i=0;i<n-1;i++){
            if(a[i]==0)
                a[i]=b[0];
            if(a[i+1]==0)
                a[i+1]=b[0];
            if(a[i+1]<a[i]){
                flag=true;
                break;
            }
        }
    }
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
