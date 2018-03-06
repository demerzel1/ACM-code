#include<bits/stdc++.h>
using namespace std;
int a[1002];
int repeat[1002];
int main(){
    int n;
    memset(a,0,sizeof(a));
    memset(repeat,0,sizeof(repeat));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
//    cout<<222<<endl;
    sort(a,a+n);

    int x=0;
    for(int i=0;i<=n-2;i++){
        if(a[i]==a[i+1]){
            repeat[x]++;
            x++;
        }
        else{
            x=0;
        }
    }
  //  cout<<111<<endl;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(repeat[i]>0)
            cnt++;
    }
    printf("%d",n-1-cnt);
    return 0;
}
