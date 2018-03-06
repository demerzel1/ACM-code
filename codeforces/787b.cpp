#include<bits/stdc++.h>
using namespace std;
#define maxn 10005

bool g[maxn][maxn];
int n,m,k;
bool flag=true;

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        if(!flag){
            scanf("%d",&k);
            int a;
            for(int i=0;i<k;i++)
                scanf("%d",&a);
            continue;
        }
        flag=false;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            int a;
            scanf("%d",&a);
            if(flag)
                continue;
            g[m][abs(a)]=!g[m][abs(a)];
            if(!g[m][abs(a)])
                flag=true;
        }
    }
    if(!flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
