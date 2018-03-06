const int INF=0x3f3f3f3f;
template <class T> struct SpanT{
    T lowc[MAXN],cost[MAXN][MAXN];
    bool vis[MAXN];
    void addedge(int a,int b,T c){cost[a][b]=cost[b][a]=c;}
    T prim(int n){//[0,n-1]
        T ans=0;
        memset(vis,0,sizeof(vis)); vis[0]=1;
        for(int i=1;i<n;i++)lowc[i]=cost[0][i];
        for(int i=1;i<n;i++){
            T minc=INF;
            int p=-1;
            for(int j=0;j<n;j++)
                if(!vis[j] && minc>lowc[j]) minc=lowc[j],p=j;
            if(minc==INF)return -1;//原图不连通
            ans+=minc,vis[p]=1;
            for(int j=0;j<n;j++)
                if(!vis[j] && lowc[j]>cost[p][j]) lowc[j]=cost[p][j];
        }
        return ans;
    }
};