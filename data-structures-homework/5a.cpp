#include<queue>
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int n,k,i,x,cur,val,pos,A[32];
    queue <int>q;
    while(scanf("%d%d",&n,&k)&&n){
        for(i=1;i<=n;i++)
            A[i]=40;
        cur=0;
        val=1;
        for(i=1;i<=n;i++)
            q.push(i);
        while(!q.empty()){
            x=q.front();
            q.pop();
            if(!cur){
                cur=val++;
                if(val>k)
                    val=1;
            }
            if(cur==A[x]){
                cur=0;
                printf("%3d",x);
            }
            else if(cur<A[x]){
                A[x]-=cur;
                cur=0;
                q.push(x);
            }
            else{
                cur-=A[x];
                printf("%3d",x);
            }
        }
//        printf("\n");
        puts("");
    }
    return 0;
}
