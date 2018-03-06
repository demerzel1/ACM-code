#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
    map<int,vector<int>>na;
    vector<int>::iterator it;

int fun(int a,int b){
    it=find(na[a].begin(),na[a].end(),b);
    if(it==na[a].end()){
        return 0;
    }else{
        return 1;
    }
}

int main()
{
    int a,b,n,x,m;
	while (cin >> n >> m){
        na.clear();
        cin>>x;
        for(int i=0;i<x;i++){
            cin>>a>>b;
        if(fun(a,b)==0){
            na[a].push_back(b);
            cout<<"YES"<<endl;
          }else{
            cout<<"NO"<<endl;
          }
        }
	}
    return 0;
}
