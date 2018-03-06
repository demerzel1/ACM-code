//Code here
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=10;
int main()
{
    int n,m;
    //cout<<5*9*5*6<<endl;
    while(scanf("%d%d",&n,&m)!=EOF){
        vector<int> po;
        vector<int> ne;
        for(int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            if(t>0) po.push_back(t);
            if(t<0) ne.push_back(t);
        }
        for(int i=0;i<po.size();i++){
            m*=po[i];
        }

        if(ne.size()%2==0){
        for(int i=0;i<ne.size();i++){
            m*=ne[i];
        }
        }
        else{
           sort(ne.begin(),ne.end());
         for(int i=0;i<ne.size()-1;i++){
            m*=ne[i];
        }
        }
        cout<<m<<endl;
    }

    return 0;
}

