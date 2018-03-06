#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
const double EPS = 1e-9;
const double PI = 2 * asin(1);
const int INF = 0x7fffffff;
const LL LINF = 0x7fffffffffffffff;

int s,n;

struct dragon {
    int x,y;
};

bool cmp(dragon a,dragon b) {
    if(a.x!=b.x)
        return a.x<b.x;
    else
        return a.y>b.y;

}
dragon d[1005];

void pretreat() {
}


bool input() {
    scanf("%d%d",&s,&n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&d[i].x,&d[i].y);
    }
}


void solve() {
    sort(d,d+n,cmp);
    int flag=0;
    for(int i=0;i<n;i++){
        if(s>d[i].x){
            s+=d[i].y;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag){
        printf("NO");
    }
    else{
        printf("YES");
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    input();
    solve();
    return 0;
}
