#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int>game;
vector<int>friends;
int ans;
int bisearch(int l,int r,int L,int R)
{
    if(l==r||L==R)
        return ans;
    int mid = (l+r)/2;
    int low = lower_bound(friends.begin()+L,friends.begin()+R,game[mid])-friends.begin();
    {
        if(low!=0&&abs(friends[low-1]-game[mid])<friends[low]-game[mid])
            low--;
    }
    ans += abs(friends[low]-game[mid]);
    bisearch(l,mid,L,low);
    bisearch(mid+1,r,low+1,R);
}
int main()
{
    int x;
   while(cin>>n>>m)
   {
       game.clear();
       friends.clear();
       for(int i=0;i<m;i++)
       {
           cin>>x;
           friends.push_back(x);
       }
       for(int i=0;i<n;i++)
       {
           cin>>x;
           game.push_back(x);
       }
       sort(friends.begin(),friends.end());
       sort(game.begin(),game.end());
       ans = 0;
       cout<<bisearch(0,game.size(),0,friends.size())<<endl;
   }
}


