#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define mn 15000
#define mx 33000
int level[mn],tree[mx];
int lb(int x){
    return x&-x;
}
void add(int x,int value){
    for(int i=x;i<=mx;i+=lb(i)) tree[i]+=value;
}
int get(int x){
    int ret=0;
    for(int i=x;i;i-=lb(i)) ret+=tree[i];
    return ret;
}
int n,_x,_y;
int main(){
    scanf("%d",&n);
    memset(level,0,sizeof(level));
    memset(tree,0,sizeof(tree));
    for(int i=0;i<n;i++){
        scanf("%d%d",&_x,&_y);
        _x++,_y++;
        level[get(_x)]++;
        add(_x,1);
    }
    for(int i=0;i<n;i++)
        printf("%d\n",level[i]);
    return 0;
}
