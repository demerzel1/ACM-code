#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <cmath>
#define MAXT 1001000
#define MAXO 1001000
using namespace std;

char TEXT[MAXT];
char OBJ[MAXO];
int TEXT_COUNT=0;
int OBJ_COUNT=0;
int NEXT[MAXO];
vector<int> result;
int rCnt=0;

void COMPUTE_PREFIX_FUNCTION()
{
    NEXT[1]=0;
    int k=0;
    for(int q=2;q<OBJ_COUNT;q++){
        while(k>0&&OBJ[k+1]!=OBJ[q]){ k=NEXT[k];}
        if(OBJ[k+1]==OBJ[q]){k++;}
        NEXT[q]=k;
    }
}

bool KMP_MATCHER(int &start){
    int q=0;
    //COMPUTE_PREFIX_FUNCTION();
    for(int i=start;i<=TEXT_COUNT;i++){
        while(q>0&&OBJ[q+1]!=TEXT[i]){
            q=NEXT[q];
        }
        if(OBJ[q+1]==TEXT[i]){
            q++;
        }
        if(q==OBJ_COUNT){
            //printf("%d\n",i-OBJ_COUNT+1);
            result.push_back(i-OBJ_COUNT+1);
            TEXT[i-OBJ_COUNT+1]=' ';
            int a=NEXT[q];
            start=i-OBJ_COUNT+1+a;
            return true;
        }
    }
    return false;
}
void init(){
    memset(TEXT,0,sizeof(char)*TEXT_COUNT);
    memset(OBJ,0,sizeof(char)*OBJ_COUNT);
    //int TEXT_COUNT=0;
    //int OBJ_COUNT=0;
    //rCnt=0;
    result.clear();
}
int main()
{
    while(scanf("%d",&TEXT_COUNT)!=EOF){
        init();
        scanf("%*c");
        TEXT[0]=' ';
        gets(&TEXT[1]);

        OBJ[0]=' ';
        scanf("%d",&OBJ_COUNT);
        scanf("%*c");
        gets(&OBJ[1]);

        int start=1;
        COMPUTE_PREFIX_FUNCTION();
        while(KMP_MATCHER(start));
        printf("%d\n",result.size());
        for(int i=1;i<result.size();i++)
        {
            printf("%d ",result[i-1]);
        }
        printf("%d\n",result.back());

    }
    return 0;
}

