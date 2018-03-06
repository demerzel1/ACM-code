#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
struct cmp{
    bool operator()(int &a,int &b){
        return a>b;
    }
};
int main(){
    priority_queue<int,vector<int>,cmp> que;
    long long int sum=0;
    int n;
    scanf("%d",&n);
    while(n--){
        int a;
        scanf("%d",&a);
        que.push(a);
    }
    while(que.size()>=2){
        int x,y;
        x=que.top();
        que.pop();
        y=que.top();
        que.pop();
        int c=x+y;
        sum+=c;
     //   printf("c=%d sum=%d\n",c,sum);
        que.push(c);
    }

    cout<<sum;
    return 0;
}
