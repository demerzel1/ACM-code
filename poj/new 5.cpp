#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;
 
struct P
{
    int id ; LL val ;
    bool operator < (const P &rhs) const
    {
        return val>rhs.val ;
    }
};
 
int n,m,k ;
LL h[maxn],a[maxn],num[maxn],p ;
priority_queue<P> pq ;
bool check(LL h0)
{
    while(!pq.empty()) pq.pop() ;
    memset(num,0,sizeof(num)) ;
    for(int i=1;i<=n;i++) if(h0-a[i]*m < h[i])
        pq.push((P){i,h0/a[i]}) ;
    for(int i=1;!pq.empty() && i<=m;i++)
        for(int _k=1;!pq.empty() && _k<=k;_k++)
    {
        P u=pq.top() ; pq.pop() ;
        if(u.val<i) return 0 ;
        num[u.id]++ ;
        if(h0+p*num[u.id]-a[u.id]*m<h[u.id])
            pq.push((P){u.id,(h0+p*num[u.id])/a[u.id]}) ;
    }
    return pq.empty() ;
}
 
main()
{
    scanf("%d%d%d%lld",&n,&m,&k,&p) ;
    LL l=0 , r=0 ;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&h[i],&a[i]) ;
        l=max(l,a[i]) ;
        r=max(r,h[i]+m*a[i]) ;
    }
    l-- ;
    while(r-l>1)
    {
        LL mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%lld\n",r) ;
}