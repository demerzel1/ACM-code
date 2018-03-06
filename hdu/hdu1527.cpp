#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        if(a>b)
            swap(a,b);
        int t=b-a;
        if(a==floor(t*(sqrt(5)+1)/2))
            cout<<0<<"\n";
        else
            cout<<1<<"\n";
    }
    return 0;
}
