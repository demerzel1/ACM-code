#include <iostream>
#include<memory.h>
#define N 100
using namespace std;
int useif[N];
int link[N];
int mat[N][N];
int gn,gm;
int can(int t){
    int i;
    for(i=1;i<=gm;i++)
    {
        if(useif[i]==0&&mat[t][i])
        {
            useif[i]=1;
            if(link[i]==-1||can(link[i])){
                link[i]=t;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch(){
    int i,num=0;
    memset(link,0xff,sizeof(link));
    for(i=1;i<=gn;i++){
        memset(useif,0,sizeof(useif));
        if(can(i))
            num++;
    }
    return num;
}
int main()
{
    while(cin>>gn>>gm){

        int i;
        cin>>i;

            memset(mat,0,sizeof(mat));

            while(i--){
                int a,b;
                cin>>a>>b;
                mat[a][b]=1;
            }
            cout<<MaxMatch()<<endl;
        }

    return 0;
}

