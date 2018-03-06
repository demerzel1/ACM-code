#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define inf 100000000
using namespace std;

int main(){
    int i,j,k,p,q;
    int g[26][26],degree[26],dist[26],sum,len,odd;
    char s[10000];

    while(scanf("%s",s)!=EOF){
        sum=0;
        for(i=0;i<26;i++){
            for(j=0;j<26;j++)
                g[i][j]=inf;
            degree[i]=0;
        }
        while(true){
            if(strcmp(s,"deadend")==0) break;
            len=strlen(s);
            p=s[0]-'a';
            q=s[len-1]-'a';
            g[p][q]=g[q][p]=len;
            sum+=len;
            degree[p]++;
            degree[q]++;
            scanf("%s",s);
        }
        odd=0;
        for(i=0;i<26;i++)
        if(degree[i]%2==1){
            odd++;
            if(odd==1) p=i;
            else q=i;
        }
        if(odd==0){
            printf("%d\n",sum);
        }
        else{
            for(k=0;k<26;k++)
                for(j=0;j<26;j++)
                    for(i=0;i<26;i++)
                        if(g[i][j]>g[i][k]+g[k][j])
                            g[i][j]=g[i][k]+g[k][j];
            printf("%d\n",sum+g[p][q]);

        }
    }
    return 0;
}
