#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
int n,temp,ans=0;
struct cmp{
    bool operator()(int a,int b){
        return a>b;
    }
};
priority_queue<int,vector<int>,cmp> q;
bool deal(){
    temp+=q.top();
    q.pop();
    if(q.empty())
        return false;
    else
        return true;
}
int main()
{
    bool have;
    int ci=2;
	while (cin >> n){
	      ans=0;
          for(int i=0;i<n;i++){
            cin>>temp;
            q.push(temp);
          }
          for(int i=0;i<n-1;i++){
            temp=0;
            for(int j=0;j<ci;j++){
                have=deal();
                if(have==false)
                  break;
            }
            //cout<<temp<<endl;
            q.push(temp);
            ans+=temp;
          }
          cout<<ans<<endl;
	}
    return 0;
}
