#include<set>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdio>
#include<iostream>
#define S second
#define F first
using namespace std;
const int MAX = 200005;
typedef long long LL;
LL xx;
set< pair<LL,int> >bridge;
pair< pair<LL,LL>,int >island[MAX];
int ans[MAX];
int main() {
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
        scanf("%I64d%I64d",&island[i].F.F,&island[i].F.S);
    for(i=1; i<=m; i++) {
        scanf("%I64d",&xx);
        bridge.insert(make_pair(xx,i));
    }
    for(i=0; i<n-1; i++) {
        LL i_min=island[i+1].F.F-island[i].F.S;
        LL i_max=island[i+1].F.S-island[i].F.F;
        island[i].S=i;
        island[i].F.F=i_max;
        island[i].F.S=i_min;
    }
    sort(island,island+n-1);
    for(i=0; i<n-1; i++) {
        set<pair<LL,int> >::iterator it;
        it=bridge.lower_bound(make_pair(island[i].F.S,0));
        if( it==bridge.end() || (it->F)>island[i].F.F ) break;
        ans[island[i].S]=it->S;
        bridge.erase(it);
    }
    if(i==n-1) {
        puts("Yes");
        for(i=0; i<n-2; i++) printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    } else puts("No");
    return 0;
}
