#include<cstdio>
#include<algorithm>
#include<cstring>
#include<list>
#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;

map<int,int>::iterator it;
map<int,int> mymap;

int c[150000],b[1500];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int n,i,t,tl,j;
    scanf("%d",&n);
    mymap.clear();
    for(i=0;i<n*n;i++){
        scanf("%d",&t);
        mymap[t]++;
    }
    for(t=0,it=mymap.begin();it!=mymap.end();it++){
        b[t++]=it->first;
    }
    for(tl=0,i=t-1;i>=0;i--){
        while(mymap[b[i]]>0){
            c[tl++]=b[i];
            mymap[b[i]]--;
            for(j=0;j<tl;j++){
                mymap[gcd(c[j],b[i])]-=2;
            }
        }
    }
    for(i=0;i<tl;i++){
        printf("%d ",c[i]);
    }
    return 0;
}
