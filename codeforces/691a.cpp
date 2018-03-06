#include <iostream>

using namespace std;

int n;
int a[1005];
int cnt;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)
            cnt++;
    }
    if((cnt==1&&n!=1)||(cnt==0&&n==1))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}