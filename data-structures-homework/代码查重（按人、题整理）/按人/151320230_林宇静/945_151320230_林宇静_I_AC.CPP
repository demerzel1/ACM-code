#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>>q;
    int n;
    while(scanf("%d",&n)!=EOF){
        while(!q.empty())
            q.pop();
        long long sum=0;
        int num;
        while(n--){
            scanf("%d",&num);
            q.push(num);
        }
        while(!q.empty()){
            int index=q.top();
            sum+=q.top();
            q.pop();
            if(q.empty())
                break;
            index+=q.top();
            sum+=q.top();
            q.pop();
            if(q.empty())
                break;
            q.push(index);
        }
        printf("%lld\n",sum);
    }
    return 0;
}

