#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
using ll=long long;
typedef struct Node {
    int a;
    int ind;
} node;

node num[maxn];
int n;
int Tree[maxn];

bool cmp(node aa,node bb) {
    return aa.a<bb.a;
}

int lowbit(int x) {
    return x&(-x);
}

void add(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i)){
        Tree[i]+=val;
    }
}
int get(int x){
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=Tree[i];
    }
    return sum;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    while(scanf("%d",&n)!=EOF) {
        memset(Tree,0,sizeof(Tree));
        for(int i=1; i<=n; i++) {
           scanf("%d",&num[i].a);
            num[i].ind=i;
        }
        sort(num+1,num+n+1,cmp);
        ll ans=0;
        for(int i=n;i>0;i--){

          //  cout<<get(n)<<" "<<get(tind[i])<<"\n";
            ans+=(ll)get(num[i].ind);
            add(num[i].ind,1);
          //  cout<<ans<<"\n";
        }
        printf("%lld\n",ans);
    }
    return 0;
}
