#include<bits/stdc++.h>
using namespace std;
#define maxn 1005

int a[maxn];
int b[maxn];
bool vis[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int cnt=0;
    int ind1=0,ind2=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(cnt==0){
                ind1=i;
                cnt++;
            }else{
                ind2=i;
                cnt++;
            }
        }else
            vis[a[i]]=true;
    }
    if(cnt==1){
        int x=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                x=i;
                break;
            }
        }
        a[ind1]=x;
    }else{
      //  cout<<11<<"\n";
        if(vis[a[ind1]]||vis[b[ind2]])
            a[ind1]=b[ind1];
        else
            a[ind2]=b[ind2];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
