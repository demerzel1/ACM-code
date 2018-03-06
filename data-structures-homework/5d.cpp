#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct node{
    int id,p,now;
    bool operator < (const node&a) const{
        if(a.now==now)
            return a.id<id;
        return a.now<now;
    }
};

int main(){
    string s;
    int i,n;
    node a;
    priority_queue<node> que;
    while(cin>>s){
        if(s=="#")
            break;
        cin>>a.id>>a.p;
        a.now=a.p;
        que.push(a);
    }
    cin>>n;
    while(n--){
        a=que.top();
        cout<<a.id<<endl;
        a.now+=a.p;
        que.pop();
        que.push(a);
    }
    return 0;
}
