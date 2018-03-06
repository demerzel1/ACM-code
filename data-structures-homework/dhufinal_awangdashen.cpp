#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int m,n;

struct cmp {
    bool operator () (long long a,long long  b) {
        return a>b;
    }
};
priority_queue<long long,vector<long long>,cmp> S;
int main() {
    int x,y;
    int i;
    long long a;
    while(scanf("%d%d",&n,&m)!=EOF) {
        if(n<=m) {
            for(i=0; i<n; i++) {
                scanf("%d%d",&x,&y);
                printf("%lld\n",x+y);
            }
        } else {
            for(i=0; i<m; i++) {
                scanf("%d%d",&x,&y);
                printf("%lld\n",x+y);
                S.push(x+y);
            }
            for(; i<n; i++) {
                scanf("%d%d",&x,&y);
                if(S.top()<=x) {
                    printf("%lld\n",x+y);
                    S.pop();
                    S.push(x+y);
                } else {
                    a=S.top();
                    S.pop();
                    printf("%lld\n",a+y);
                    S.push(a+y);
                }
            }
            while(!S.empty()) {
                S.pop();
            }
        }
    }

    return 0;
}
