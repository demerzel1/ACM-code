#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int f[30010],num[30010];
int find(int x){
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}
int main(){
    int t;
    cin>>t;
    for(int N,M,j=0;j<t&&cin>>N&&N;++j){
        cin>>M;
        memset(num,0,sizeof(num));
        for(int i=1;i<=N;++i){
            f[i]=i;
        }
        for(int x,y,i=0;i<M&&scanf("%d%d",&x,&y);++i){
            f[find(x)]=f[find(y)];
        }
        for(int i=1;i<=N;++i){
            num[find(i)]++;
        }
        int ans=-1;
        for(int i=1;i<=N;++i){
            ans=max(ans,num[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
