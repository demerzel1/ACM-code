#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 105
struct edge{
    int from,to,cost;
};
int d[maxn];
vector<edge> es;
int V,E;
void bellman_ford(int s){
  //  printf("get in b_f \n");
    for(int i=1;i<=V;i++)
        d[i]=-1;
    d[s]=10000000;
 //   printf("s=%d V=%d\n",s,V);
    while(true){
        bool update=false;
        for(int i=0;i<2*E;i++){
            edge e=es[i];
       //     printf("from=%d to=%d cost=%d\n",e.from,e.to,e.cost);
        //    printf("d:::from=%d to=%d cost=%d\n",d[e.from],d[e.to],e.cost);
            if(d[e.from]!=-1&&d[e.to]<min(d[e.from],e.cost)){

                d[e.to]=min(d[e.from],e.cost);
       //        cout<<"updated!!"<<endl;
       //         printf("up::d:::from=%d to=%d cost=%d\n",d[e.from],d[e.to],e.cost);
                update=true;
            }
        }
        if(!update) break;
    }
}
int cnt=1;
int main(){
    while(scanf("%d%d",&V,&E)){
        if(V==0&&E==0)
            break;


        edge te;
        for(int i=1;i<=E;i++){
            scanf("%d%d%d",&te.from,&te.to,&te.cost);
            es.push_back(te);
            edge te2;
            te2.from=te.to;
            te2.to=te.from;
            te2.cost=te.cost;
            es.push_back(te2);
        }
        int start,ends,people;
        scanf("%d%d%d",&start,&ends,&people);
        bellman_ford(start);
      //  printf("aaaaaaa\n");
        printf("Scenario #%d\n",cnt);
   //     printf("d[ends]=%d\n",d[ends]);
        int times=ceil(people*1.0/((d[ends]-1)*1.0));
        printf("Minimum Number of Trips = %d\n\n",times);
        cnt++;
        es.clear();
    }
    return 0;
}
