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
#define maxn 105

int n,m;
int boy[maxn],girl[maxn];
vector<int> G[maxn];
bool useif[maxn];
int link[maxn];

void pretreat() {

}


bool input() {
    if(scanf("%d",&n)==EOF)
        return false;
    for(int i=0; i<n; i++) {
        scanf("%d",&boy[i]);
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++) {
        scanf("%d",&girl[i]);
    }
    return true;
}

void jianbian() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(fabs(boy[i]-girl[j])<=1) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
}


int can(int t) {
    int i;
    for(i=0; i<G[i].size(); i++) {
        if(useif[i]==0) {
            useif[i]=1;


            if(link[i]==-1 || can(link[i])) {
                link[i]=t;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch() {
    int i,num;
    num=0;
    memset(link,-1,sizeof(link));
    for(i=0; i<n; i++) {
        memset(useif,0,sizeof(useif));
        if(can(i))
            num++;
    }
    return num;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    while(input()) {
        jianbian();
        int x=MaxMatch();
        printf("%d\n",n+m-2*x);
        for(int i=0;i<n;i++)
            G[i].clear();
    }

    return 0;
}

