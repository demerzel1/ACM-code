#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

class node{
public:
    int x,y;
    node(int a=0,int b=0){
        x=a;y=b;
    }
};

class edge{
public:
    int from,to;
    int value;
    int id;
    edge(int f=0,int t=0,int v=0,int i=0){from=f;to=t;value=v;id=i;}
    bool operator<(const edge &e) const {return value>e.value;}
};

class ed{
public:
    int from,to;
    int value;
    int id;
    ed(int f,int t,int v,int i){from=f;to=t;value=v;id=i;}
    bool operator<(const ed &e) const {return id>e.id;}
};

int part[1010];
int crank[1010];

void ini(){
    for(int i=0;i<1010;i++){
        part[i]=i;
    }
    memset(crank,0,sizeof(crank));
}

int cfind(int nodeNum){
    if(part[nodeNum]==nodeNum) return nodeNum;
    else return part[nodeNum]=cfind(part[nodeNum]);
}

int unite(int a,int b){
    a=cfind(a);
    b=cfind(b);
    if(a==b) return -1;
    if(crank[a]<crank[b]){
        part[a]=b;
        return b;
    }else {
        part[b]=a;
        if(crank[a]==crank[b]){
            crank[a]++;
        }
        return a;
    }
}

edge eeee[1001000];
int main()
{
    int point,e;
    while(scanf("%d %d",&point,&e)!=EOF){
        priority_queue<edge> que;
        deque<int> q;
 
        for(int i=1;i<=e;i++){
            int f,t,v;
            scanf("%d %d %d",&f,&t,&v);
            que.push(edge(f,t,v,i));
            eeee[i]=edge(f,t,v,i);
        }

        ini();
        int result=0;
        for(int i=1;i<=point-1;i++){
            int a;
            scanf("%d",&a);
            q.push_back(a);
        }

        priority_queue<ed> ie;
        while(!que.empty()){
            edge e=que.top();
            que.pop();
            int flag=unite(e.from,e.to);
            //ie.push(ed(e.from,e.to,e.value,e.id));
            if(flag!=-1){
                result+=e.value;
            }
        }
    

        ini();
        while(!q.empty()){
            int a=q.front();
            q.pop_front();
            int flag=unite(eeee[a].from,eeee[a].to);
            if(flag!=-1) result-=eeee[a].value;
        }
        bool f=true;
        int root=cfind(1);
        for(int i=1;i<=point;i++){
            if(cfind(i)!=root){
                f=false;
                break;
            }
        }
        
        if(f==true&&result==0) printf("YES\n");
        else printf("NO\n");


    }

    return 0;
}

