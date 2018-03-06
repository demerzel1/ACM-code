#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==0&&b==0)
        printf("NO");
    else if(b-a==1||a==b||a-b==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
