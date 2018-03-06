#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define MAXN 101

using namespace std;
class node{
public:
    double x,y;
    node(double a=0,double b=0){x=a;y=b;}
};

double dis(node a,node b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

bool DFS(vector<vector<int>>gMap,bool used[MAXN],int match[MAXN],int v){
    for(int i=0;i<gMap[v].size();i++){
        int u=gMap[v][i];
        if(!used[u]){
            used[u]=true;
            if(match[u]==-1||DFS(gMap,used,match,match[u])){
                match[u]=v;
                return true;
            }
        }
    }
    return false;
}

int bMatch(int leftCnt,vector<vector<int>>gMap){
    int res=0;
    bool used[MAXN]={false};
    int match[MAXN]={0};
    memset(match,-1,sizeof(match));
    for(int i=0;i<leftCnt;i++){
        memset(used,0,sizeof(used));
        if(DFS(gMap,used,match,i)){res++;}
    }
    return res;
}

int main()
{
    int gopherCnt,holeCnt,limTime,speed;

    int a,b,n,x,m;
	while (cin >> n >> m){
        vector<vector<int>>gMap;
        gMap.resize(max(n,m)+1);
        cin>>x;
        for(int i=0;i<x;i++){
            cin>>a>>b;
            gMap[a].push_back(b);
        }
        int result=bMatch(max(n,m),gMap);
        printf("%d\n",result);
	}

    //while(scanf("%d %d %d %d",&gopherCnt,&holeCnt,&limTime,&speed)!=EOF){
        /*vector<node>gopXY;
        while(gopherCnt--){
            double x,y;
            scanf("%lf %lf",&x,&y);
            gopXY.push_back(node(x,y));
        }

        vector<node>holeXY;
        while(holeCnt--){
            double x,y;
            scanf("%lf %lf",&x,&y);
            holeXY.push_back(node(x,y));
        }

        double maxDis=speed*limTime;
        gMap.resize(max(gopXY.size(),holeXY.size())+1);

        for(int i=0;i<gopXY.size();i++){
            for(int j=0;j<holeXY.size();j++){
                if(dis(gopXY[i],holeXY[j])<=maxDis){
                    gMap[i].push_back(j);
                }
            }
        }
*/
    //}
    return 0;
}

