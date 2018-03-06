#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
#define maxn 10000005
vector<int> mp[maxn];
int main() {
    while(scanf("%d",&n)!=EOF) {
            scanf("%d",&m);
        int q;
        for(int i=0;i<maxn;i++)
            mp[i].clear();
        scanf("%d",&q);
        for(int i=0; i<q; i++) {
            int xi;
            int yi;
            scanf("%d%d",&xi,&yi);
            bool flag=false;
            for(int j=0;j<mp[xi].size();j++){
                if(yi==mp[xi][j]){
                    flag=true;
                    break;
                }
            }
            if(flag!=true){
                mp[xi].push_back(yi);
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}


