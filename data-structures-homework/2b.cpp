#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> mp;
    int N,M;
    char name[60];
    int score;
    int LMrank;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        getchar();
        gets(name);
        mp[name]=0;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        LMrank=1;
        for(int j=0;j<N;j++){
            scanf("%d",&score);
            getchar();
            gets(name);
            mp[name]+=score;
        }
        map<string,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
            if(it->second>mp["Li Ming"])
                LMrank++;
        printf("%d\n",LMrank);
    }
     return 0;
}
