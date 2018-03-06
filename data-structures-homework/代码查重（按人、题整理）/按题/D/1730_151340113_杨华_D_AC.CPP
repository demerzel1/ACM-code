#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

class PlayGames{
private:
    vector<int>friendsl;
    vector<int>myl;
    int sum;
    int n,m;
    int getminfrend(int l,int r,int val);
public:
    void initial(int N,int M);
    void read();
    void computing();
    void outresult(){printf("%d\n",sum);}
};
int PlayGames::getminfrend(int l,int r,int val){
    int mid = (l+r) >> 1;
    if(mid == l){
        if(fabs(friendsl[l] - val) >= fabs(friendsl[r] - val)){
            return r;
        }
        else{
            return l;
        }
    }
    if(val == friendsl[mid]){
        return mid;
    }
    else if(val > friendsl[mid]){
        return getminfrend(mid,r,val);
    }
    else{
        return getminfrend(l,mid,val);
    }
}
void PlayGames::initial(int N,int M){
    n = N;
    m = M;
    sum = 0;
    friendsl.clear();
    myl.clear();
}
void PlayGames::read(){
    int l;
    for(int i = 0;i < m;i++){
        scanf("%d",&l);
        friendsl.push_back(l);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&l);
        myl.push_back(l);
    }
    sort(friendsl.begin(),friendsl.end());
}
void PlayGames::computing(){
    for(int i = 0;i < n;i++){
        sum += fabs(myl[i] - friendsl[getminfrend(0,m-1,myl[i])]);
    }
}

int main()
{
    PlayGames pg;
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        pg.initial(n,m);
        pg.read();
        pg.computing();
        pg.outresult();
    }
    return 0;
}
