#include<bits/stdc++.h>
using namespace std;
int graph[30][30];
char order[30];
int indegree[30];
int flag[30];
vector<char> ans;
void topological(){
    int i;
    while(1){
        for(i=0;order[i]!='\0';i++){
            if(indegree[i]==0&&!flag[i]){
                break;
            }
        }
        ans.push_back(order[i]);
        flag[i]=1;
        for(int j=0;j<30;j++){
            if(graph[i][j]!=0){
                graph[i][j]=0;
                indegree[j]--;
            }
        }
        int j;
        for(j=0;flag[j]!=0;j++){
            break;
        }
        if(flag[i]==0)
            break;
    }
    return;
}
int main(){
    memset(order,'\0',sizeof(order));
    memset(graph,0,sizeof(graph));
    memset(indegree,0,sizeof(indegree));
    memset(flag,0,sizeof(flag));
    string s1,s2;
    cin>>s1;
    int cnt;
    while(1){
        cin>>s2;
        if(s2=="#")
            break;
        int cur;
        for(int i=0;i<=min(s1.length(),s2.length());i++){
            if(s1[i]!=s2[i]){
                cur=i;
                break;
            }
        }
        if(cur!=min(s1.length(),s2.length())){
            char c=s1[cur];
            int i=0;
            for(i=0;order[i]!='\0';i++){
                if(order[i]==c)
                    break;
            }
            if(order[i]=='\0'){
                order[i]=c;
            }
            char c2=s2[cur];
            int j=0;
            for(j=0;order[j]!='\0';j++){
                if(order[j]==c2)
                    break;
            }
            if(order[j]=='\0'){
                order[j]=c2;
            }
            graph[i][j]=1;
            indegree[j]++;
        }
        s1=s2;
    }
    for(int i=0;order[i]!='\0';i++)
        printf("%c ",order[i]);
    printf("\n");
    for(int i=0;order[i]!='\0';i++){

    }
    topological();
    for(int i=0;i<ans.size();i++)
        printf("%c",ans[i]);
    return 0;
}
