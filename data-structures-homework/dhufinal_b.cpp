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
int L[maxn];
bool square[maxn][maxn];
int rudu[maxn];
void pretreat() {
    memset(L,0,sizeof(L));
    memset(rudu,0,sizeof(rudu));
    memset(square,false,sizeof(square));
}


bool input() {
    if(scanf("%d%d",&n,&m)==EOF)
        return false;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        square[a][b]=true;
        rudu[b]++;
    //    printf("rudu[b]=%d b=%d\n",rudu[b],b);
    }
    return true;
}


void solve() {
    int pos=0;
    queue<int> que;
    int x;
    for(int i=1;i<=n;i++){
     //       printf("rudu=%d i=%d\n",rudu[i],i);
        if(rudu[i]==0){
            x=i;
            que.push(x);
        }

    }
  //  printf("x=%d\n",x);

    while(!que.empty()){
      //      cout<<111<<endl;
        int x=que.front();
        que.pop();
        L[pos++]=x;
        for(int i=1;i<=n;i++){
            if(square[x][i]==true){
                rudu[i]--;
        //        printf("i=%d\n",i);
                square[x][i]=false;
                if(rudu[i]==0){
                    que.push(i);
      //              cout<<"push"<<endl;
                }
            }
        }
    }
   // printf("pos=%d\n",pos);
    if(pos==n){
        for(int i=0;i<n-1;i++){
            printf("%d ",L[i]);
        }
        printf("%d\n",L[n-1]);
    }
    else{
        printf("-1\n");
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

     pretreat();
    while(input()){

        solve();
        pretreat();
    }

    return 0;
}
