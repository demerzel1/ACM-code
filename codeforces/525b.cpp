#include<bits/stdc++.h>
using namespace std;
#define maxn 200005

char str[maxn];
int f[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>str;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        f[x-1]++;
    }
    int l=strlen(str);
    for(int i=1;i<l/2;i++){
        f[i]+=f[i-1];
     //   cout<<f[i]<<" "<<i<<"\n";
    }
    for(int i=l/2;i<l;i++){
        f[i]=f[l-i-1];
    //    cout<<f[i]<<" "<<i<<"\n";
    }
    for(int i=0;i<l;i++){
      //  if(i==0)
     //   cout<<111<<"\n";
     //   cout<<f[i]<<" "<<i<<"\n";
        if(f[i]%2==0){
            cout<<str[i];
        }

        else{
            cout<<str[l-i-1];
        }

    }
    return 0;
}
