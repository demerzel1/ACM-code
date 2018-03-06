#include<bits/stdc++.h>
using namespace std;
#define maxn 105
const double INF=pow(10,300);
typedef struct node{
    double x,y;
}node;
node N[maxn];
int vis[maxn];
double dist[maxn][maxn];
int p[maxn];
int num;

double dis(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
    int ncase;
    cin>>ncase;
    while(ncase--){
        cin>>num;
        for(int i=0;i<num;i++){
            cin>>N[i].x>>N[i].y;
        }
        for(int i=0;i<num;i++){
            for(int j=i;j<num;j++){
                dist[i][j]=dist[j][i]=dis(N[i],N[j]);
            }
        }
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        p[0]=0;
        double re=0;
        for(int i=1;i<num;i++){
                double tmp=INF;
                int mark1;
                for(int j=0;j<i;j++)
                for(int k=0;k<num;k++){
                    if(vis[k]==0&&tmp>=dist[p[j]][k]){
                        mark1=k;
                        tmp=dist[p[j]][k];
                    }
                }
                re+=tmp;
                p[i]=mark1;
                vis[mark1]=1;
        }
        printf("%.2lf\n",re);
        if(ncase) cout<<endl;
    }
    return 0;
}
