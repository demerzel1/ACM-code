#include <cstring>
#include <iostream>
#include <cstdio>
#include <list>

using namespace std;
typedef long long LL;
LL Next[1000000+500];
LL ans_t;
list<LL> ans_list;
LL len_t;
LL len_p;
char tar[1000006];
char par[1000006];



void getNext()
{
    LL j,k;
    j=0;k=-1;Next[0]=-1;
    while(j<len_p){
        if(k==-1||par[j]==par[k]) Next[++j]=++k;
        else k=Next[k];
    }
}

LL KMP_count()
{
    ans_list.clear();
    LL i=0;LL j=0;
    getNext();
    LL ans=0;
    if(len_t==1&&len_p==1){
        if(par[0]==tar[0]) {ans_list.push_back(1);return 1;}
    }
    for(i=0;i<len_t;i++){
        while(j>0&&tar[i]!=par[j]) j=Next[j];
        if(tar[i]==par[j]) j++;
        if(j==len_p) {ans++;if(ans_list.size()<1200)ans_list.push_back(i-len_p+2);j=Next[j];}
    }
    return ans;
}

int main()
{
    while(EOF!=scanf("%lld",&len_t)){
        getchar();
        gets(tar);
        scanf("%lld",&len_p);
        for(int i=0;i<len_t;i++)
        {
          if(tar[i]>='a'&&tar[i]<='z') {tar[i]=tar[i]-'a'+'A';}
        }
        getchar();
        gets(par);
                for(int i=0;i<len_p;i++)
        {
          if(par[i]>='a'&&par[i]<='z') {par[i]=par[i]-'a'+'A';}
        }
        ans_t=KMP_count();
        printf("%lld\n",ans_t);
        ans_t=min(ans_t,(LL)999);
        for(LL i=0;i<ans_t;i++){
            if(i!=0) printf(" ");
            printf("%lld",ans_list.front());
            ans_list.pop_front();
        }
        printf("\n");
    }
    return 0;
}


