#include<bits/stdc++.h>
using namespace std;

void king(int n,int m){
    if((n%2==1)&&(m%2==1))
        cout<<"G\n";
    else
        cout<<"B\n";
    return;
}

void rook(int n,int m){
//    n--;
//    m--;
    if((n^m)==0)
        cout<<"G\n";
    else
        cout<<"B\n";
    return;
}

void knight(int n,int m){
    n--;
    m--;
    if((n+m)%3==0){
        if(n==m)
            cout<<"G\n";
        else if(n==m+1||m==n+1)
            cout<<"B\n";
        else
            cout<<"D\n";
    }else
        cout<<"D\n";
    return;
}

void queen(int n,int m){
    n--;
    m--;
    if(n>m)
        swap(n,m);
    int t=m-n;
    if(n==int(t*(sqrt(5)+1)/2.0))
        cout<<"G\n";
    else
        cout<<"B\n";
    return;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int op,n,m;
        cin>>op>>n>>m;
        switch(op){
        case 1:
            king(n,m);
            break;
        case 2:
            rook(n,m);
            break;
        case 3:
            knight(n,m);
            break;
        case 4:
            queen(n,m);
            break;
        }
    }
    return 0;
}
