#include<bits/stdc++.h>
using namespace std;

bool judge(int a,int b,int c) {
    if(b==0&&c==0||b!=0&&c!=0||a!=0&&(b>1||c>1))
        return true;
    return false;
}

int main() {
    int n;
    scanf("%d",&n);
    char s[205];
    getchar();
    int r=0,g=0,b=0;
    for(int i=0; i<n; i++) {
        char c;
        scanf("%c",&c);
        if(c=='R')  r++;
        if(c=='G')  g++;
        if(c=='B')  b++;
    }
    if(judge(b,g,r))    printf("B");
    if(judge(g,r,b))    printf("G");
    if(judge(r,g,b))    printf("R");
    return 0;
}
