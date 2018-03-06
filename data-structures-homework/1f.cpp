#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int Day[3655];
int Party[101];
int main(){
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++){
        memset(Day,0,3655);
        memset(Party,0,101);
        int N,D;
        scanf("%d%d",&D,&N);
        int j;
        for(j=0;j<N;j++)
            scanf("%d",&Party[j]);
        for(j=0;j<N;j++)
            for(int k=0;k<=D;k+=Party[j])
                Day[k]=1;
        for(j=0;j<=D;j+=7)
            Day[j]=0;
        for(j=6;j<=D;j+=7)
            Day[j]=0;

        int sum=0;
        for(j=0;j<=D;j++)
            sum+=Day[j];
        cout<<sum<<endl;
    }
    return 0;
}
