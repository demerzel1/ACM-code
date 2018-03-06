//3

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000005;

int N,M,Q;
map<pair<int,int>,bool> sign;

int main()
{
    while(cin>>N>>M>>Q){
        sign.clear();
        for(int i=0;i<Q;i++){
            int x,y;
            cin>>x>>y;

            if(sign.find(pair<int,int>(x,y))!=sign.end()){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                sign[pair<int,int>(x,y)] = true;
            }
        }
    }
    return 0;
}

