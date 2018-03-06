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
#define maxn 10005

int n;
bool tree[maxn][maxn];
int E[maxn*2];
int L[maxn*2];
int R[maxn];
int rudu[maxn];
int deep=-1;
int pos=1;
int qa,qb;
void dfs(int x){
    deep++;
    R[x]=pos;
    E[pos]=x;
    L[pos]=deep;
    pos++;
    for(int i=1;i<=n;i++){
        if(tree[x][i]==true){
            dfs(i);
            E[pos]=x;
            L[pos]=deep;
            pos++;
        }
    }

    deep--;
    return;
}

int solve(){
    int first_qa=R[qa];
    int first_qb=R[qb];
  //  printf("fa=%d fb=%d\n",first_qa,first_qb);
    int mindeep=100000;
    int l=min(first_qa,first_qb);
    int r=max(first_qa,first_qb);
    int mini=l;
    for(int i=l;i<=r;i++){
        if(mindeep>L[i]){
            mindeep=L[i];
            mini=i;
     //       printf("mindeep=%d\n",mindeep);
        }
    }
  //  printf("i=%d\n",mini);
    return E[mini];
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	int T;
	scanf("%d",&T);
	while(T--){
        memset(tree,false,sizeof(tree));
        memset(E,0,sizeof(E));
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        memset(rudu,0,sizeof(rudu));
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            tree[a][b]=true;
            rudu[b]++;
        }
        int root;
        for(int i=1;i<=n;i++)
            if(rudu[i]==0){
                root=i;
                break;
            }
        dfs(root);

        scanf("%d%d",&qa,&qb);
        int ans=solve();
        printf("%d\n",ans);
//        for(int i=1;i<=2*n-1;i++)
//            printf("%d ",E[i]);
//        printf("\n");
//        for(int i=1;i<=2*n-1;i++)
//            printf("%d ",L[i]);
//        printf("\n");
//        for(int i=1;i<=n;i++)
//            printf("%d ",R[i]);
//        printf("\n");
	}
	return 0;
}
