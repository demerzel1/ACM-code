#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int A[33];
bool flag[33];
int B[33];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        char str[5];
        for(int i=0;i<n;i++){
            scanf("%s",str);
            if(str[0]>=2&&str[0]<='9')A[i]=(str[0]-'0')*10;
            if(str[0]=='T')A[i]=100;
            if(str[0]=='J')A[i]=110;
            if(str[0]=='Q')A[i]=120;
            if(str[0]=='K')A[i]=130;
            if(str[0]=='A')A[i]=140;

            if(str[1]=='H')A[i]+=4;
            if(str[1]=='S')A[i]+=3;
            if(str[1]=='D')A[i]+=2;
            if(str[1]=='C')A[i]+=1;
        }
        for(int i=0;i<n;i++){
            scanf("%s",str);
            if(str[0]>=2&&str[0]<='9')B[i]=(str[0]-'0')*10;
            if(str[0]=='T')B[i]=100;
            if(str[0]=='J')B[i]=110;
            if(str[0]=='Q')B[i]=120;
            if(str[0]=='K')B[i]=130;
            if(str[0]=='A')B[i]=140;

            if(str[1]=='H')B[i]+=4;
            if(str[1]=='S')B[i]+=3;
            if(str[1]=='D')B[i]+=2;
            if(str[1]=='C')B[i]+=1;
        }
        sort(B,B+n);
        memset(flag,0,sizeof(flag));
        for(int i=0;i<n;i++){
            int maxx=0;
            int pos=-1;
            for(int j=0;j<n;j++){
                if(flag[j])continue;
                if(B[i]>A[j]&&A[j]>maxx){
                    maxx=A[j];
                    pos=j;
                }
            }
            if(pos!=-1)flag[pos]=true;
        }
        int cnt=0;
        for(int i=0;i<n;i++)if(flag[i])cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
