#include <cstring>
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

int Next[1000000+500];
int ans_t;
list<int> ans_list;
int len_t;
int len_p;
char tar[1000006];
char par[1000006];



void getNext()
{
    int j,k;
    j=0;k=-1;Next[0]=-1;
    while(j<len_p){
        if(k==-1||par[j]==par[k]) Next[++j]=++k;
        else k=Next[k];
    }
}

int KMP_count()
{
    ans_list.clear();
    int i=0;int j=0;
    getNext();
    int ans=0;
    if(len_t==1&&len_p==1){
        if(par[0]==tar[0]) {ans_list.push_back(1);return 1;}
    }
    for(i=0;i<len_t;i++){
        while(j>0&&tar[i]!=par[j]) j=Next[j];
        if(tar[i]==par[j]) j++;
        if(j==len_p) {ans++;ans_list.push_back(i-len_p+2);j=Next[j];}
    }
    return ans;
}

int main()
{
    while(EOF!=scanf("%d",&len_t)){
        getchar();
        gets(tar);
        scanf("%d",&len_p);
        getchar();
        gets(par);
        ans_t=KMP_count();
        printf("%d\n",ans_t);
        for(int i=0;i<ans_t;i++){
            if(i!=0) printf(" ");
            printf("%d",ans_list.front());
            ans_list.pop_front();
        }
        printf("\n");
    }
    return 0;
}


