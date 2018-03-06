#include<cstdio>
#include<algorithm>
#include<cstring>
#include<list>
#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
struct node{
    int v;
    list<node>::iterator it;
};

map<int,list<node> > xl,yl;

int main(){
    int N,M;
    while(scanf("%d%d",&N,&M)){
            if(N==0&&M==0)
                break;
            xl.clear();
            yl.clear();
        for(int i=0;i<N;i++){
            int x,y;
            scanf("%d%d",&x,&y);
     //       printf("x%d y%d\n",x,y);
            list<node>::iterator ix,iy;
            node n;
            ix=xl[x].insert(xl[x].end(),n);
            iy=yl[y].insert(yl[y].end(),n);
            ix->it=iy;
            iy->it=ix;
            ix->v=y;
            iy->v=x;
        }
        for(int i=0;i<M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==0){
                printf("%d\n",xl[b].size());
                for(list<node>::iterator i=xl[b].begin();i!=xl[b].end();i++){
                    yl[i->v].erase(i->it);
                }
                xl[b].clear();
            }else{
                printf("%d\n",yl[b].size());
                for(list<node>::iterator i=yl[b].begin();i!=yl[b].end();i++ ){
                    xl[i->v].erase(i->it);
                }
                yl[b].clear();
            }
        }
        cout<<endl;
    }
    return 0;
}
