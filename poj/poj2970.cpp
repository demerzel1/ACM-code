#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>
#include <iomanip>
using namespace std;
#define maxn 100005
typedef long long ll;
struct Node {
    int a;
    int b;
    int d;
    bool operator <(const Node &x) const {
        return a<x.a;
    }
} node[maxn];
int cmp(Node x,Node y) {
    return x.d<y.d;
}

priority_queue<Node> que;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0; i<n; i++) {
           scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].d);
        }
        sort(node,node+n,cmp);
        ll sum=0;
        double ans=0;
        for(int i=0; i<n; i++) {
            que.push(node[i]);
            sum+=node[i].b;
            while(!que.empty()&&sum>node[i].d) {
                Node x=que.top();
                que.pop();
                if(sum-node[i].d>x.b) {
                    ans+=x.b*1.0/x.a;
                    sum-=x.b;
                } else {
                    ans+=(sum-node[i].d)*1.0/x.a;
                    x.b-=sum-node[i].d;
                    sum=node[i].d;
                    que.push(x);
                }
            }
        }
        printf("%.2f",ans);
    }
    return 0;
}


