#include<bits/stdc++.h>
using namespace std;
#define maxm 35
#define maxn 40
int n,m;
int volunteer[maxm][2];
int tshirt[maxn];
int useif[maxn];
int link[maxn];
int biao[maxm][maxn];
void input(){
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        if(a=="XS")
            volunteer[i][0]=0;
        if(a=="S")
            volunteer[i][0]=1;
        if(a=="M")
            volunteer[i][0]=2;
        if(a=="L")
            volunteer[i][0]=3;
        if(a=="XL")
            volunteer[i][0]=4;
        if(a=="XXL")
            volunteer[i][0]=5;
        if(b=="XS")
            volunteer[i][1]=0;
        if(b=="S")
            volunteer[i][1]=1;
        if(b=="M")
            volunteer[i][1]=2;
        if(b=="L")
            volunteer[i][1]=3;
        if(b=="XL")
            volunteer[i][1]=4;
        if(b=="XXL")
            volunteer[i][1]=5;
    }
//    for(int i=0;i<m;i++)
//        printf("%d %d\n",volunteer[i][0],volunteer[i][1]);
}
void init(){
    int num=0;
    for(int i=0;i<n/6;i++){
        for(int j=1;j<=6;j++){
            tshirt[num]=i;
            num++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<=1;j++){
            for(int l=0;l<=5;l++){
                if(volunteer[i][j]==l){
                for(int k=l;k<n;k+=6){
                    biao[i][k]=1;
                }
            }
            }

        }
    }
//    for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//            printf("%d ",biao[i][j]);
//         }
//        printf("\n");
//    }

}

int can(int t)
{
    int i;
    for(i=0;i<n;i++){
       if(useif[i]==0 &&biao[t][i]==1)
       {
           useif[i]=1;


	  if(link[i]==-1 || can(link[i])){
              link[i]=t;
              return 1;
           }
       }
    }
    return 0;
}
int MaxMatch()
{
    int i,num;
    num=0;
    memset(link,-1,sizeof(link));
    for(i=0;i<m;i++)
    {
      memset(useif,0,sizeof(useif));
        if(can(i))
            num++;
    }
return num;
}

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        memset(volunteer,0,sizeof(volunteer));
        memset(biao,0,sizeof(biao));
        scanf("%d%d",&n,&m);
        input();
        init();
        int ans=MaxMatch();
//        cout<<ans<<endl;
        if(m==ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
