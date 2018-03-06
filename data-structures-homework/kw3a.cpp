#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int c1=0;
    int c2=0;
    while(N--){
        int a,b;
        cin>>a>>b;
        if(a>b)
            c1++;
        if(a<b)
            c2++;
    }
    if(c1>c2)
        cout<<"Mishka";
    if(c1==c2)
        cout<<"Friendship is magic!^^";
    if(c1<c2)
        cout<<"Chris";
    return 0;
}
