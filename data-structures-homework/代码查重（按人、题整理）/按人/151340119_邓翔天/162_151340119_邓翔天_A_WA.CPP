#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int turn,mon;
int ele[100];
int maxmon;
int main()
{
    while(EOF!=scanf("%d%d",&turn,&mon)){
            maxmon=1;
        int sum=(int)(0.5+pow(2,turn+1))-1;
        //cout<<sum<<endl;
        for(int i=0;i<turn;i++){
            scanf("%d",&ele[i]);
        }
        for(int i=0;i<sum;i++){
                int pt=0;
                int t_mon=mon;
                int ti=i;
            while(ti>0){
                int bit=ti%2;
                if(bit==1) t_mon*=ele[pt];
                ti=ti/2;
                pt++;
            }
        if(t_mon>maxmon) maxmon=t_mon;
        t_mon=0;
        }
        printf("%d\n",maxmon);
    }
    return 0;
}

