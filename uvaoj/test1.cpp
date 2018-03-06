#include <cstdio>
#include <queue>
#define rep(x,n) for(x=n;x<13;x++)
using namespace std;
bool judge(int a[]){
    queue<int> q;
    q.push(a[0]);
    int c=0,find[20]={0};
    for(int i=0;i<5;i++){
        find[a[i]]=1;
    }
    if(a[0]==3&&a[1]==6&&a[2]==7&&a[3]==8&&a[4]==11){
        printf("test\n");
    }
    int vis[20]={0};
    vis[a[0]]=1;
    while(!q.empty()){
        int t=q.front();
        //printf("%d\n",t);
        q.pop();
        c++;
        if(t-1>0&&vis[t-1]!=1&&find[t-1]&&t!=5&&t!=9){
            vis[t-1]=1;
            q.push(t-1);
        }
        if(t-4>0&&vis[t-4]!=1&&find[t-4]){
            vis[t-4]=1;
            q.push(t-4);
        }
        if(t+1<12&&vis[t+1]!=1&&find[t+1]&&(t!=4&&t!=8))
        {
            vis[t+1]=1;
            q.push(t+1);
        }
        if(t+4<12&&vis[t+4]!=1&&find[t+4]){
            vis[t+4]=1;
            q.push(t+4);
        }

    }
    if(c==5)return true;
    return false;
}
int main(){
    int a[6],count=0;
    rep(a[0],1)rep(a[1],a[0])rep(a[2],a[1])rep(a[3],a[2])rep(a[4],a[3]){
    //rep(a[0],1)rep(a[1],1)rep(a[2],1)rep(a[3],1)rep(a[4],1){
        if(a[0]==a[1]||a[0]==a[2]||a[0]==a[3]||a[0]==a[4]||a[1]==a[2]||a[1]==a[3]||a[1]==a[4]||a[2]==a[3]||a[2]==a[4]||a[3]==a[4])
        continue;
        if(judge(a)){

            int find[20]={0};
            for(int i=0;i<5;i++){
                find[a[i]]=1;
            }
            printf("Case%d:\n",count+1);
            for(int i=1;i<=3;i++){
                for(int j=1;j<5;j++){
                    if(find[(i-1)*4+j])printf("%3c",'*');
                    else printf("%3d",(i-1)*4+j);
                }
                printf("\n");
            }

            count++;
        }

        //printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
    }
    printf("count:%d\n",count);
    return 0;
}
/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int a[12]= {1,2,3,4,6,7,8,9,11,12,13,14},vis[20];
int main()
{
    int sum=0;
    for(int i1=0; i1<12; i1++)
        for(int i2=i1+1; i2<12; i2++)
            for(int i3=i2+1; i3<12; i3++)
                for(int i4=i3+1; i4<12; i4++)
                    for(int i5=i4+1; i5<12; i5++)
                    {
                        memset (vis,0,sizeof(vis));
                        int p=0;
                        vis[a[i1]]=1;
                        vis[a[i2]]=1;
                        vis[a[i3]]=1;
                        vis[a[i4]]=1;
                        vis[a[i5]]=1;
                        queue<int>q;
                        q.push(a[i1]);
                        vis[a[i1]]=0;
                        while(!q.empty())
                        {
                            int top=q.front();
                            q.pop();
                            p++;
                            if(vis[top+1]) { q.push(top+1);vis[top+1]=0; }
                            if(vis[top+5]) { q.push(top+5);vis[top+5]=0; }
                            if(vis[top-1]) { q.push(top-1);vis[top-1]=0; }
                            if(vis[top-5]) { q.push(top-5);vis[top-5]=0; }
                        }
                        if(p==5)
                        {
                            sum++;
                            cout<<a[i1]<<" "<<a[i2]<<" "<<a[i3]<<" "<<a[i4]<<" "<<a[i5]<<endl;
                        }
                    }
    cout<<sum<<endl;

    return 0;
}
*/
