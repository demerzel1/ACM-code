#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
using pii=pair<int,int>;
using ull=unsigned long long;
#define mod 1000000009
int m;
struct point{
    int x,y;
}cube[maxn];
map<pii,int> mp;
set<int> st;
int tans[maxn];
int up[3][2]={{0,1},{-1,1},{1,1}};
int down[3][2]={{0,-1},{-1,-1},{1,-1}};

int CountDown(const pii &t){
    int cnt=0;
    for(int j=0;j<3;j++){
        int x=t.first+down[j][0];
        int y=t.second+down[j][1];
        pii p=make_pair(x,y);
        auto it=mp.find(p);
        if(it!=mp.end()) cnt++;
    }
    return cnt;
}

bool ifInSet(int i){
    for(int j=0;j<3;j++){
        int x=cube[i].x+up[j][0];
        int y=cube[i].y+up[j][1];
        pii p=make_pair(x,y);
        auto it=mp.find(p);
        if(it!=mp.end()&&CountDown(p)<=1)
            return false;
    }
    return true;
}

int Vasya(){
    auto it=st.end();
    int t=0;
    while(!st.empty()){
        it=st.end();
        it--;
        if(ifInSet(*it)){
            t=*it;
            st.erase(it);
            break;
        }else
            st.erase(it);
    }
    pii p=make_pair(cube[t].x,cube[t].y);
    auto mpit=mp.find(p);
    mp.erase(mpit);
    for(int i=0;i<3;i++){
        int x=cube[t].x+down[i][0];
        int y=cube[t].y+down[i][1];
        p=make_pair(x,y);
        auto itt=mp.find(p);
        if(itt!=mp.end()&&ifInSet(itt->second)){
            st.insert(itt->second);
        }
    }
    return t;
}

int Petya(){
    auto it=st.begin();
    int t=0;
    while(!st.empty()){
        it=st.begin();
        if(ifInSet(*it)){
            t=*it;
            st.erase(it);
            break;
        }else
            st.erase(it);
    }
    pii p=make_pair(cube[t].x,cube[t].y);
    auto mpit=mp.find(p);
    mp.erase(mpit);
    for(int i=0;i<3;i++){
        int x=cube[t].x+down[i][0];
        int y=cube[t].y+down[i][1];
        p=make_pair(x,y);
        auto itt=mp.find(p);
        if(itt!=mp.end()&&ifInSet(itt->second)){
            st.insert(itt->second);
        }
    }
    return t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>cube[i].x>>cube[i].y;
        mp[make_pair(cube[i].x,cube[i].y)]=i;
    }
    for(int i=0;i<m;i++){
        if(ifInSet(i)){
            st.insert(i);
        }
    }
    for(int i=0;i<m;i++){
        if(i%2==0){
            tans[i]=Vasya();
        }else{
            tans[i]=Petya();
        }
    }
    ull ans=0,b=1;
    for(int i=m-1;i>=0;i--){
        ans=(ans+tans[i]*b)%mod;
        b=(b*m)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
