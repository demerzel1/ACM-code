#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int main(){
    long long n;
    cin>>n;
    long long a=sqrt(n);
    for(int i=0;i<maxn;i++){
        if(n%(a-i)==0){
            cout<<a-i<<" "<<n/(a-i);
           break;
        }
    }
    return 0;
}
