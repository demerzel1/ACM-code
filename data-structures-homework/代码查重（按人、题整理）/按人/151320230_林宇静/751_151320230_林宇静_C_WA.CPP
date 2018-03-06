#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    map<long long,int> p;
    int n,m,q;
    while(~scanf("%d%d",&n,&m)){
        p.clear();
        scanf("%d",&q);
        int x,y;
        for(int i=0;i<q;i++){
            scanf("%d%d",&x,&y);
            if(!p[x*m+y]){
                printf("YES\n");
                p[x*m+y]=1;
            }
            else
                printf("NO\n");
        }
    }
    return 0;
}

