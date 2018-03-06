bool dfs(int x,int c){
    col[x]=c;
    for(const auto &i:g[x]){
        if(col[i]!=-1){
            if(col[i]==c)
                return false;
        }else{
            if(!dfs(i,c^1))
                return false;
        }
    }
    return true;
}

bool paint(){
    memset(col,-1,sizeof(col));
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            if(!dfs(i,0))
                return false;
        }
    }
    return true;
}
