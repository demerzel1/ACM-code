#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main() {
    int n;
    int cnt=0;
    int t=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(i+1==a) {
            cnt++;
        } else
            mp[a]++;
    }
    map<int,int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++) {
        if(it->second>=1) {
            t++;
        }
    }
    cnt+=t/2;
    printf("%d",cnt);
    return 0;
}
