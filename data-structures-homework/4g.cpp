#include<cstdio>
#include<cstring>
#define MAXX 222

short dg[MAXX];
short n,r,i,j;

int main(){
    while(scanf("%hd %hd",&n,&r)!=EOF){
        memset(dg,0,sizeof(dg));
        while(r--)
            scanf("%hd %hd",&i,&j),++dg[i],++dg[j];
        for(i=0;i<n;++i)
            if(!dg[i]||dg[i]&1)
                break;
        if(i<n)
            puts("Not Possible");
        else
            puts("Possible");
    }
    return 0;
}
