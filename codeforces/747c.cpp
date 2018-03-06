#include<bits/stdc++.h>
using namespace std;
int num[100];
struct point {
    int id;
    int endtime;
    bool operator < (const point &a) const {
        return endtime > a.endtime;
    }
} p;
int n;
int m;
priority_queue<int, vector<int>, greater<int> >q1;
priority_queue<point> q2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        q1.push(i);
    }
    while(m--) {
        int t,k,d;
        cin>>t>>k>>d;
        while(!q2.empty()) {
            p=q2.top();
            if(p.endtime>t) {
                break;
            } else {
                q2.pop();
                q1.push(p.id);
            }
        }
        int len=q1.size();
        if(len>=k) {
            int cnt=0;
            while(k--) {
                int aaaaa=q1.top();
                q1.pop();
                p.id=aaaaa;
                p.endtime=t+d;
                cnt+=aaaaa;
                q2.push(p);
            }
            cout<<cnt<<"\n";
        } else {
            cout<<"-1\n";
        }
    }
    return 0;
}
