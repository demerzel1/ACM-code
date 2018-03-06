#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char s[100];
bool bo[100][100];
int hx[101000],hy[101000];
int c[4]={0,1,0,-1},d[4]={1,0,-1,0};
bool check(int x1,int y1){
    int i,head=0,tail=1,x,y,xx,yy,num=0,sum=0;
    x=x1;
    y=y1;
    while(bo[x][y]){
        x+=c[1];
        y+=d[1];
        num++;
    }
    x=x1+num/2;
    y-=num/2;
    while(bo[x][y]){
        x+=c[0];
        y+=d[0];
        sum++;
    }
    hx[1]=x1;
    hy[1]=y1;
    bo[x1][y1]=false;
    do{
        x=hx[++head];
        y=hy[head];
        for(i=0;i<4;i++){
            xx=x+c[i];
            yy=y+d[i];
            if(bo[xx][yy]){
                bo[xx][yy]=false;
                hx[++tail]=xx;
                hy[tail]=yy;
            }
        }
    }while(head<tail);
}
