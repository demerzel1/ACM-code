#include<bits/stdc++.h>

using namespace std;
int main() {
    long n;
    int p,c,m=0,s[10000];
    memset(s,0,sizeof(s));
    cin>>n;
    p=16;
    if(n==0)
        cout<<0;
    while (n!=0) {
        c=n%p;
        n=n/p;
        m++;
        s[m]=c;
    }
    for(int k=m; k>=1; k--) {
        if(s[k]>=10)
            cout<<(char)(s[k]+55);
        else
            cout<<s[k];
    }
    return 0;
}
