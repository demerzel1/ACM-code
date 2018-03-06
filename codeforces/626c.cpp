#include<bits/stdc++.h>
using namespace std;

int n,m;

bool ok(int x){
    if(x/2<n)
        return false;
    if(x/3<m)
        return false;
    if(x/2+x/3-x/6<n+m)
        return false;
    return true;
}

int main() {
    scanf("%d%d",&n,&m);
    int l=0;
    int r=10000000;
    while(l+1<r) {
        int mid=(l+r)/2;
        if(ok(mid))
            r=mid;
        else
            l=mid;
    }
    printf("%d",r);
    return 0;
}
