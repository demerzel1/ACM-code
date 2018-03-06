#include<bits/stdc++.h>
using namespace std;
#define maxn 15
int a[maxn];

void init() {
    a[1]=1;
    for(int i=2; i<11; i++)
        a[i]=a[i-1]*(4*i-2)/(i+1);
}

int main() {
    init();
    int n;
    int cas=0;
    while(cin>>n) {
        if(cas!=0)
            cout<<"\n";
        cout<<a[n]<<"\n";
        cas++;
    }
    return 0;
}
