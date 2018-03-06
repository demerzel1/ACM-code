#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
struct cmp{
    bool operator()(int a,int b){
        return a>b;
    }
};

int main()
{
    priority_queue<int,vector<int>,cmp> q;
    int n,temp,ans=0;
	while (cin >> n){
            ans=0;
          for(int i=0;i<n;i++){
            cin>>temp;
            q.push(temp);
          }
          for(int i=0;i<n;i++){
            temp=0;
            temp+=q.top();
            q.pop();
            if(q.empty())
                break;
            temp+=q.top();
            q.pop();
            q.push(temp);
            ans+=temp;
          }
          cout<<ans<<endl;
	}
    return 0;
}
