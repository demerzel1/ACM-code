struct Dsu{
    int fa[MAXN];
    void clear(){memset(fa,-1,sizeof(fa));}
    Dsu(){clear();}
    int find(int x){return fa[x]<0?x:fa[x]=find(fa[x]);}
    bool join(int a,int b){
        a=find(a);b=find(b); if(a==b) return 0;
        if(fa[a]<fa[b]) fa[a]+=fa[b],fa[b]=a;
        else            fa[b]+=fa[a],fa[a]=b;
        return 1;
    }
};