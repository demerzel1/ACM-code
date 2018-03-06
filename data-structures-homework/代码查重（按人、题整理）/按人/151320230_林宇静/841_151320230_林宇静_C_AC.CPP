#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    map<long long,int> p;
    int n,m,q;
    while(scanf("%d%d",&n,&m)!=EOF){
        p.clear();
        scanf("%d",&q);
        int x,y;
        for(int i=0;i<q;i++){
            scanf("%d%d",&x,&y);
            if(p[y*n+x]==0){
                p[y*n+x]=1;
                printf("YES\n");
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}

