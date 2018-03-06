#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
struct cmp {
    bool operator () (long long &a,long long &b) {
        return a>b;
    }
};

priority_queue<LL,vector<LL>,cmp> que;
int main() {
    while(scanf("%d",&n)!=EOF) {
        LL ans=0;
        for(int i=0; i<n; i++) {
            LL x;
            scanf("%lld",&x);
            que.push(x);
        }
        while(que.size()>1) {
            LL a=que.top();
            que.pop();
            LL b=que.top();
            que.pop();
            // cout<<a<<" "<<b<<endl;
            LL c=a+b;
            ans+=c;
            //cout<<c<<endl;
            que.push(c);
        }
        cout<<ans<<endl;
        while(!que.empty()){
            que.pop();
        }
    }
    return 0;
}


