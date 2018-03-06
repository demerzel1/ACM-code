#include<bits/stdc++.h>
using namespace std;
#define maxn 200005

string s,t;
int a[maxn];
int sz,sz1;

bool judge(int x){

}

int main() {
    cin>>t>>p;
    sz=t.size();
    sz1=p.size();
    for(int i=1; i<=sz; i++)
        cin>>a[i];
    int l=t.size();
    int r=sz;
    int ans=r;
    while(l<=r) {
        mid=(l+r)>>1;
        if(judge(mid)) {
            l=mid+1;
            ans=mid;
        } else
            r=mid-1;
    }
}
