#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int m[102][102];
void out(int x,int l){
    int d=-10;
    int r=-1;
    for(int i=1;i<=x;i++){
        if(m[l][i]>d){
            d=m[l][i];
            r=i;
        }
    }
    printf("The longest path from %d has length %d, finishing at %d.\n\n",l,d,r);
}

int main(){
    int N,d,cas=1;
    while(cin>>N){
        int a=-1,b=-1;
        if(N==0)
            break;
        cin>>d;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                m[i][j]=-1500;
        while(true){
     //       cout<<"test"<<endl;
            if(a==0&&b==0)
                break;
            cin>>a>>b;
            m[a][b]=1;
           }
            for(int k=1;k<=N;k++)
                for(int i=1;i<=N;i++)
                    for(int j=1;j<=N;j++)
                        m[i][j]=max(m[i][k]+m[k][j],m[i][j]);

                        printf("Case %d: ",cas);
                        cas++;
            out(N,d);


    }
    return 0;
}
