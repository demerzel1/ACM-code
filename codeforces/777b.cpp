#include<bits/stdc++.h>
using namespace std;

int a[1005],b[1005];

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char c=getchar();
        a[i]=c-'0';
    }
    getchar();
    for(int i=0;i<n;i++){
        char c=getchar();
        b[i]=c-'0';
    }
    sort(a,a+n);
    sort(b,b+n);
    int ansmin=0,ansmax=0;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){

        }
    }
    return 0;
}
