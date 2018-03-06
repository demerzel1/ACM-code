#pragma warning (disable:4996)
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const double EPS = 1e-9;
const double PI = 2 * asin(1);
const int INF = 0x7fffffff;
const LL LINF = 0x7fffffffffffffff;

vector<LL> val;
struct Segment_tree{
    vector<LL>date,lazy;
    void initial(int n){
        date.clear(),date.resize(n<<2);
        lazy.clear(),lazy.resize(n<<2);
    }
    int l_son(int root){
        return root<<1;
    }
    int r_son(int root){
        return root<<1|1;
    }
    int get_mid(int l,int r){
        return (l+r)>>1;
    }
    void push_up(int root){
        int ls=l_son(root),rs=r_son(root);
        date[root]=max(date[ls],date[rs]);
    }
    void push_down(int root){
        if(lazy[root]==0)
            return;
        int ls=l_son(root),rs=r_son(root);
        auto k=lazy[root];
        lazy[root]=0;
        date[ls]=k,date[rs]=k;
        lazy[ls]=k,lazy[rs]=k;
    }
    void built(int root,int l,int r){
        if(l==r){
            date[root]=val[l];
            return;
        }
        int mid=get_mid(l,r);
        int ls=l_son(root),rs=r_son(root);
        built(ls,l,mid),built(rs,mid+1,r);
        push_up(root);
    }
    void update_sg(int root,int l,int r,int u,int v,LL k){
        if(u<=l&&v>=r){
            date[root]=k;
            lazy[root]=k;
            return;
        }
        push_down(root);
        int mid=get_mid(l,r);
        int ls=l_son(root),rs=r_son(root);
        if(u<=mid)
            update_sg(ls,l,mid,u,v,k);
        if(v>mid)
            update_sg(rs,mid+1,r,u,v,k);
        push_down(root);
    }
    LL query(int root,int l,int r,int u,int v){
        if(u<=l&&v>=r){
            return date[root];
        }
        push_down(root);
        int mid=get_mid(l,r);
        int ls=l_son(root),rs=r_son(root);
        if(v<=mid){
            return query(ls,l,mid,u,v);
        }
        if(u>mid)
            return query(rs,mid+1,r,u,v);
        return max(query(ls,l,mid,u,v),query(rs,mid+1,r,u,v));
    }
};






void pretreat() {
}


bool input() {
}


void solve() {
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    input();
    solve();
    return 0;
}

