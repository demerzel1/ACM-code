#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
struct node {
    int x;
    int y;
      bool operator == (const node &a){
        if(x==a.x&&y==a.y)
            return true;
        return false;
      }
      bool operator <(const node&a) const{
        if(a.x<x)
            return true;
        else if(a.y<y){
            return true;
        }
        return false;
      }


}p;
map<node,int> mp;
int main() {
    while(scanf("%d",&n)!=EOF) {
            scanf("%d",&m);
        mp.clear();
        int q;
        scanf("%d",&q);
        for(int i=0; i<q; i++) {
            int xi;
            int yi;
            scanf("%d%d",&p.x,&p.y);
            if(mp[p]==0) {
                mp[p]+=1;
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}

