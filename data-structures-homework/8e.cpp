#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int sum[111111],ans[111111],n;

struct Query{
    int l,r,id,val;
    bool operator <(const Query &it) const{
        if(val!=it.val) return val<it.val;
        return id<it.id;
    }
}q[222250];

void update(int x){
    for(;x<n;x+=~x&(x+1)) sum[x]++;
}

int query(int x){
    int ret=0;
    for(;x>=0;x-=~x&(x+1)) ret+=sum[x];
    return ret;
}

int main(){
    int t,m;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d",&n,&m);
        memset(sum,0,sizeof(sum[0])*n);
        for(int i=1;i<=n;i++)
            scanf("%d",&q[i].val),q[i].id=i-1;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&q[i+n].l,&q[i+n].r,&q[i+n].val),q[i+n].id=i+n;
        sort(q+1,q+n+m+1);
        for(int i=1;i<=n+m;i++)
            if(q[i].id>n)
                ans[q[i].id-n]=query(q[i].r)-query(q[i].l-1);
            else update(q[i].id);
        printf("Case %d:\n",cas);
        for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
