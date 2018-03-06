#include<bits/stdc++.h>
using namespace std;
#define maxn 105

int n,m,s,v;
double gopher[maxn][2];
double hole[maxn][2];
int useif[maxn];
int link[maxn];
int getin(int i,int j){
    double q=sqrt((gopher[i][0]-hole[j][0])*(gopher[i][0]-hole[j][0])+(gopher[i][1]-hole[j][1])*(gopher[i][1]-hole[j][1]));
   // cout<<i<<" "<<j<<" "<<q<<endl;
    if(s*v>q)
        return 1;
    else return 0;
}

int can(int t) {
    int i;
    for(i=0; i<m; i++) {
        if(useif[i]==0 &&getin(t,i)) {
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

int main(){
    while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF){
    //    printf("%d %d %d %d",n,m,s,v);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&gopher[i][0],&gopher[i][1]);
          //  cout<<gopher[i][0]<<" "<<gopher[i][1]<<endl;
        }

        for(int i=0;i<m;i++)
            scanf("%lf%lf",&hole[i][0],&hole[i][1]);
        cout<<n-MaxMatch()<<endl;
    }
    return 0;
}
