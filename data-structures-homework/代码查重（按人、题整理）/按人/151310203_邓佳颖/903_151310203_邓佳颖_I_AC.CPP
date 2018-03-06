//Code here
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            q.push(t);
        }
        long long int ans=0;
        while(q.size()>1){
            long long int a=q.top();
            q.pop();
            long long int b=q.top();
            q.pop();
            ans+=a+b;
            q.push(a+b);
        }
        cout << ans<< endl;
    }

    return 0;
}

