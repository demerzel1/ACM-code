#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define Max 20005
using namespace std;

struct noname{
    int x,y,ans;
}node[Max];

int n;
void dfs(int l,int r,int k,int c){
    while(k<n&&(r<node[k].x||l>node[k].y)){
        cout<<"k++죄！"<<endl;
        k++;
    }

    if(k>=n){
        node[c].ans+=r-l+1;
        return;
    }
    if(l<node[k].x){
        cout<<"가가가가x"<<endl;
        dfs(l,node[k].x-1,k+1,c);
    }

    if(r>node[k].y){
        cout<<"가가가가y"<<endl;
        dfs(node[k].y+1,r,k+1,c);
    }

}
int main(){
    int t,sum;
    cin>>t;
    while(t--){
        sum=0;
        memset(node,0,sizeof(node));
        cin>>n;
        for(int i=0;i<n;++i)
            scanf("%d%d",&node[i].x,&node[i].y);
        for(int i=n-1;i>=0;--i)
            dfs(node[i].x,node[i].y,i+1,i);
        for(int i=0;i<n;i++)
            if(node[i].ans>0)
                ++sum;
        printf("%d\n",sum);
    }
    return 0;
}
