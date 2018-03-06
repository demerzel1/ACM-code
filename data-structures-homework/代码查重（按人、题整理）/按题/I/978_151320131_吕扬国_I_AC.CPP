#include <iostream>
#include <queue>
using namespace std;

struct e{
    int s;
    friend bool operator <(e a,e b){
    return a.s>b.s;
    };
};
int n;
int main()
{
    int i,k;
    priority_queue<e>q;
    while(cin>>n)
    {
    e b;
    for(i=1;i<=n;i++)
    {
        cin>>b.s;
        q.push(b);
    }
    int ans=0;
    while(1)
    {
        k=q.top().s;
        q.pop();
        if(q.empty())
            break;
        k+=q.top().s;
        q.pop();
        ans+=k;
        b.s=k;
        q.push(b);
    }
    cout<<ans<<endl;
    }
    return 0;
}

