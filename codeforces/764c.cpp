#include <cstdio>
int n,u[100010],v[100010],c[100010],d[100010],e;
int main() {
    scanf("%d",&n);
    for(int i=1; i<n; i++)
        scanf("%d%d",u+i,v+i);
    for(int i=1; i<=n; i++)
        scanf("%d",c+i);
    for(int i=1; i<n; i++)
        if(c[u[i]]!=c[v[i]])
            e++,d[u[i]]++,d[v[i]]++;
    for(int i=1; i<=n; i++)
        if(d[i]==e)
            return!printf("YES\n%d\n",i);
    puts("NO");
    return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//#define maxn 100005
//
//vector<int> G[maxn];
//int n;
//int col[maxn];
//bool vis[maxn];
//int root;
//bool flag=true;
//bool check[maxn];
//
//bool dfs(int x) {
//    if(vis[x]==true||flag==false)
//        return flag;
//    if(x==root) {
//        vis[x]=true;
//        for(int i=0; i<G[x].size(); i++) {
//            dfs(G[x][i]);
//        }
//    } else {
//        vis[x]=true;
//        for(int i=0; i<G[x].size(); i++) {
//            if(col[x]==col[G[x][i]]||G[x][i]==root) {
//                dfs(G[x][i]);
//            } else {
//       //         printf("x=%d Gxi=%d root=%d\n",x,G[x][i],root);
//                flag=false;
//                return flag;
//            }
//        }
//    }
//    return flag;
//}
//
//int main() {
//    scanf("%d",&n);
//    for(int i=1; i<n; i++) {
//        int u,v;
//        scanf("%d%d",&u,&v);
//        G[u].push_back(v);
//        G[v].push_back(u);
//    }
//    int cnt=0;
//    for(int i=1; i<=n; i++) {
//        int c;
//        scanf("%d",&c);
//        col[i]=c;
//    }
//    bool f=true;
//    for(int i=1; i<=n; i++) {
//        for(int j=0;j<G[i].size();j++){
//      //      cout<<111<<endl;
//            if(!check[i]){
//       //         printf("i=%d\n",i);
//                root=i;
//                check[i]=true;
//                memset(vis,false,sizeof(vis));
//                flag=true;
//                if(dfs(i)){
//                    f=false;
//                    printf("YES\n%d\n",i);
//                    break;
//                }
//            }
//            if(!check[G[i][j]]){
//      //          printf("gij=%d\n",G[i][j]);
//                root=G[i][j];
//                check[G[i][j]]=true;
//                memset(vis,false,sizeof(vis));
//                flag=true;
//                if(dfs(G[i][j])){
//                    f=false;
//                    printf("YES\n%d\n",G[i][j]);
//                    break;
//                }
//            }
//        }
//        if(!f)
//            break;
//    }
//    if(f)
//        printf("NO");
//    return 0;
//}
//
