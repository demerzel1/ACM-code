#include<bits/stdc++.h>
using namespace std;
char s[23][203];
int n,m,i,j,t[20],r[20],l[20],l1,r1=10000000,l2,r2,sol;
int main() {
    cin>>n>>m;
    for(i=n; i>0; i--)
        cin>>s[i],l[i]=m;
    for(i=1; i<=n; i++)
        for(j=0; j<m+2; j++)
        if(s[i][j]=='1')
        t[i]=1,l[i]=min(l[i],j),r[i]=max(r[i],j);
    for(i=1; i<=n; i++) {
        if(t[i]==0) {
            l1++;
            r1++;
            continue;
        }
        sol=min(l1+r[i],r1+m+1-l[i]);
        l2=min(l1+2*r[i]+1,r1+m+2);
        r2=min(r1+2*(m+1-l[i])+1,l1+m+2);
        l1=l2;
        r1=r2;
    }
    cout<<sol;
    return 0;
}
