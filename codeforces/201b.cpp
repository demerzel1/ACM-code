#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
typedef long long ll;
int m,n;
ll si[maxn];
ll sj[maxn];
const ll LINF = 0x7fffffffffffffff;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            scanf("%d",&a);
            si[i]+=a;
            sj[j]+=a;
        }
   //     printf("i=%d si=%d\n",i,si[i]);
    }
//    for(int j=0;j<m;j++)
//        printf("j=%d sj=%d\n",j,sj[j]);
    ll sumx=LINF,sumy=LINF;
    int x=0,y=0;
    for(int i=0;i<=n;i++){
        ll tx=0;
        for(int j=2;j<n*4;j+=4){
            tx+=si[j/4]*(i*4-j)*(i*4-j);
        }
        if(sumx>tx){
            sumx=tx;
            x=i;
        }
    }
    for(int i=0;i<=m;i++){
        ll ty=0;
        for(int j=2;j<m*4;j+=4){
            ty+=sj[j/4]*(i*4-j)*(i*4-j);
        }
        if(sumy>ty){
            sumy=ty;
            y=i;
        }
    }
    printf("%lld\n%d %d",sumx+sumy,x,y);
    return 0;
}
