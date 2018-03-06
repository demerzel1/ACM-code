#include<bits/stdc++.h>
using namespace std;

int main(){
    int ax,ay,bx,by,cx,cy;
    scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
    printf("3\n");
    printf("%d %d\n",bx+cx-ax,by+cy-ay);
    printf("%d %d\n",ax+cx-bx,ay+cy-by);
    printf("%d %d\n",bx+ax-cx,by+ay-cy);
    return 0;
}
