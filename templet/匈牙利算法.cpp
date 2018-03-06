
int from[maxn],tot;
bool use[maxn];

bool match(int x){
    for(const auto &i:g[x]){
        if(!use[i]){
            use[i]=true;
            if(from[i]==-1||match(from[i])){
                from[i]=x;
                from[x]=i;
                return true;
            }
        }
    }
    return false;
}

int hungary(){
    tot=0;
    memset(from,-1,sizeof(from));
    for(int i=1;i<=n;i++){
        if(from[i]!=-1)
            continue;
        memset(use,0,sizeof(use));
        if(match(i))
            tot++;
    }
    return tot;
}
