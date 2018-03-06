#include<bits/stdc++.h>
using namespace std;

bool vis[105];
int ind=0;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(vis,false,sizeof(vis));
        ind=1;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            if(s=="New"){
                vis[ind]=true;
                printf("%d\n",ind);
                for(int j=ind+1;j<101;j++){
                    if(vis[j]==false){
                        ind=j;
                        break;
                    }
                }
            }
            else if(s=="Delete"){
                int x;
                cin>>x;
                if(vis[x]==true){
                    vis[x]=false;
                    if(x<ind)
                        ind=x;
                  //  printf("de ind=%d\n",ind);
                    printf("Successful\n");
                }else
                    printf("Failed\n");
            }
        }
    }
    return 0;
}
