#include<bits/stdc++.h>
using namespace std;
#define maxnk 25
#define maxnp 1005

int category[maxnk];
int pool[maxnp][maxnk];
int np,nk;
int sumofcate[105];
int NumofCate[maxnp];
int biao[maxnp][105];
int link[105];
int useif[105];
int sum=0;
void init(){
    int s=0,e=0;
    for(int i=0;i<nk;i++){
        for(s=e,e+=category[i];s!=e;s++){
            sumofcate[s]=i+1;
        }
    }
    for(int i=0;i<nk;i++){
        sum+=category[i];
    }

//    for(int i=0;i<sum;i++)
//        printf("%d ",sumofcate[i]);
//    printf("\n");

    for(int i=0;i<np;i++){
        for(int j=0;j<NumofCate[i];j++){
            for(int k=0;k<sum;k++){
                if(pool[i][j]==sumofcate[k]){
                    biao[i][k]=1;
                }
            }
        }
    }
//    for(int i=0;i<np;i++){
//        for(int j=0;j<sum;j++){
//            printf("%d ",biao[i][j]);
//        }
//        printf("\n");
//    }
}

int can(int t)
{
    int i;
    for(i=0;i<sum;i++){
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
    for(i=0;i<np;i++)
    {
      memset(useif,0,sizeof(useif));
        if(can(i))
            num++;
    }
return num;
}

void print(){
    int s=0,e=0;
    for(int i=0;i<nk;i++){
            for(s=e,e+=category[i];s!=e;s++){
                printf("%d ",link[s]+1);
            }
            printf("\n");
        }
}


int main(){
    while(1){
        scanf("%d%d",&nk,&np);
        if(nk==0&&np==0)
            break;

        sum=0;
        memset(category,0,sizeof(category));
        memset(pool,0,sizeof(pool));
        memset(NumofCate,0,sizeof(NumofCate));
        memset(biao,0,sizeof(biao));
        memset(sumofcate,0,sizeof(sumofcate));
        for(int i=0;i<nk;i++)
            scanf("%d",&category[i]);
        for(int i=0;i<np;i++){
            scanf("%d",&NumofCate[i]);
            for(int j=0;j<NumofCate[i];j++)
                scanf("%d",&pool[i][j]);
        }


//        for(int i=0;i<np;i++){
//            for(int j=0;j<NumofCate[i];j++){
//                printf("%d ",pool[i][j]);
//            }
//            printf("\n");
//        }


        init();
        int ans=MaxMatch();
//        printf("%d\n",ans);
        if(sum==ans){
            printf("1\n");
            print();
        }
        else
            cout<<0<<endl;

    }
    return 0;
}

