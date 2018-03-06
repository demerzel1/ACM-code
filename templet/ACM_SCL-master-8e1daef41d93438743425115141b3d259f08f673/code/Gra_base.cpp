struct Gra{
    int tot,head[MAXN];
    struct Edge{
        int to,next;
    }edge[MAXM<<1];
    void clear(){
        tot=0;
        memset(head,-1,sizeof(head));
    }
    void addedge(int u,int v){
        edge[tot].to=v;
        edge[tot].next=head[u];
        head[u]=tot++;
    }//单向边
}gra;