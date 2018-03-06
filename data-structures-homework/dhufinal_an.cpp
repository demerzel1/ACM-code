#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
struct cmp1 {
    bool operator ()(long long &a,long long &b) {
        return a>b;//最小值优先
    }
};

int main() {
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF) {
        priority_queue<long long,vector<long long>,cmp1> que;
        int cnt=0;
        for(int i=0; i<n; i++) {
            long long ta,tw;
            //scanf("%d%d",&ta,&tw);
            cin>>ta>>tw;
            if(cnt<k) {
                que.push(ta+tw);
                cnt++;
              //  cout<<ta+tw<<endl;
                  printf("%lld\n",ta+tw);
            } else {
                if(que.top()>ta) {
                    long long x=que.top()+tw;
                 //   cout<<x<<endl;
                      printf("%lld\n",x);
                    que.pop();
                    que.push(x);
                } else {
                    que.pop();
                 //   cout<<ta+tw<<endl;
                       printf("%lld\n",ta+tw);
                    que.push(ta+tw);
                }
            }
        }
    }

    return 0;
}
