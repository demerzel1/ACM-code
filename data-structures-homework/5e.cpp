#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int maxn=205;
int T,n,x,y;
char s[maxn];
struct card{
    int x,y;
    card(){};
    card(int x,int y):x(x),y(y){}
    bool operator <(const card& a){
        if(x==a.x)
            return y<a.y;
        return x<a.x;
    }
}a[maxn],b[maxn];

void get(int &x,int &y){
    scanf("%s",s);
    if(s[0]=='T') x=10;
    else if(s[0]=='J') x=11;
    else if(s[0]=='Q') x=12;
    else if(s[0]=='K') x=13;
    else if(s[0]=='A') x=14;
    else x=s[0]-'0';
    if(s[1]=='C') y=0;
    if(s[1]=='D') y=1;
    if(s[1]=='S') y=2;
    if(s[1]=='H') y=3;
}
int main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            get(x,y);
            b[i]=card(x,y);
        }
        for(int i=0;i<n;i++){
            get(x,y);
            a[i]=card(x,y);
        }
        sort(a,a+n);
        sort(b,b+n);
        int i,j;
        for(i=j=0;i<n&&j<n;){
            if(b[i]<a[j])   ++i,++j;
            else ++j;
        }
        printf("%d\n",i);
    }
    return 0;
}
