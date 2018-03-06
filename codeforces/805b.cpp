#include<bits/stdc++.h>
using namespace std;

char a[6]={'a','a','b','b'};

int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        printf("%c",a[cnt]);
        cnt++;
        if(cnt==4)
            cnt=0;
    }
    return 0;
}
