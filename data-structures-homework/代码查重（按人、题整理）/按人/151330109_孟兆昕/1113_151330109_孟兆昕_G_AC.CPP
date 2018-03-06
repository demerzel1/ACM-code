#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k;
#define maxn 105
int mp[maxn][maxn];
int useif[maxn];
int link[maxn];

int can(int t){
 //  cout<<111<<endl;
    int i;
    for(i=1;i<=m;i++){

        if(useif[i]==0&&mp[t][i]){
          //  cout<<222<<endl;
            useif[i]=1;
         //   printf("t=%d i=%d\n",t,i);
            if(link[i]==-1||can(link[i])){
                link[i]=t;

                return 1;
            }
        }
    }
    return 0;
}
int Maxmatch(){
    int i,num;
    num=0;
    memset(link,-1,sizeof(link));
    for(i=1;i<=n;i++){
        memset(useif,0,sizeof(useif));
        if(can(i)){
        //    printf("i=%d\n",i);
            num++;
        }

    }
    return num;
}

int main() {
    while(scanf("%d",&n)!=EOF) {
        memset(mp,0,sizeof(mp));
        scanf("%d",&m);
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b]=1;
        }
//        for(int i=0;i<=n;i++){
//            for(int j=0;j<=m;j++)
//                printf("%d ",mp[i][j]);
//            printf("\n");
//        }
        int ans=Maxmatch();
        cout<<ans<<endl;
    }
    return 0;
}


