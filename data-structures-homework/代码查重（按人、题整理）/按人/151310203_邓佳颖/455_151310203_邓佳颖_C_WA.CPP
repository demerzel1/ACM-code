//Code here
#include <iostream>
#include <map>
using namespace std;


int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        map<long long int,int> m;
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            long long int t=x*10000000+y;
            if(m.find(t)==m.end()){
                printf("YES\n");
                m[t]++;
            }
            else{
               printf("NO\n");
            }
        }
    }
    return 0;
}

