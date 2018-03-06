#include <bits/stdc++.h>
using namespace std;

const int maxn=3005;
typedef long long ll;

#define lowbit(x) (x&-x)

int n,m;

ll data[2][2][maxn][maxn];

void add(int a,int b,ll c){
    for(int i=a;i<maxn;i+=lowbit(i)){
        for(int j=b;j<maxn;j+=lowbit(j)){
            data[a&1][b&1][i][j]^=c;
        }
    }
}
ll query(int a,int b){
    ll r=0;
    for(int i=a;i;i-=lowbit(i)){
        for(int j=b;j;j-=lowbit(j)){
            r^=data[a&1][b&1][i][j];
        }
    }
    return r;
}

char s[10];

int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(data,0,sizeof(data));
        while(m--){
            scanf("%s",s);
            if(s[0]=='P'){
                ll op=0;
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                int k;
                scanf("%d",&k);
                int x,y;
                for(int i=0;i<k;i++){
                    scanf("%d%d",&x,&y);
                    if(y&1){
                        op^=(1LL<<(x-1));
                    }
                }
                add(x1,y1,op);
                add(x1,y2+1,op);
                add(x2+1,y1,op);
                add(x2+1,y2+1,op);
            }else{
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x1--;
                y1--;
                ll ans=query(x2,y2)^query(x1,y2)^query(x2,y1)^query(x1,y1);
                for(int i=0;i<50;i++){
                    printf("%d ",((ans>>i)&1)?2:1);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
