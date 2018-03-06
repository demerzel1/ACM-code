template<char L='A',char R='z'> struct AC{
    int son[MAXN][R-L+1],fail[MAXN],end[MAXN];
    int root,Len;
    int newnode(){
        memset(son[Len],-1,sizeof(son[Len]));
        end[Len++]=0;
        return Len-1;
    }
    void clear(){Len=0;root=newnode();}
    AC(){clear();}
    void insert(const string& s){
        int now=root;
        for(const auto&c:s){
            if(son[now][c-L]== -1){
                son[now][c-L]=newnode();
            }
            now=son[now][c-L];
        }
        end[now]++;
    }
    void build(){
        queue<int>Q;
        fail[root]=-1;
        int now=root,p=-1;
        Q.push(now);
        while(!Q.empty()) {
            now=Q.front();Q.pop();
            for(int i=0;i<=R-L;i++){
                if(son[now][i]!=-1){
                    if(now==root) fail[son[now][i]]=root;
                    else{
                        for(p=fail[now];~p;p=fail[p]){
                            if(son[p][i]!=-1){
                                fail[son[now][i]]=son[p][i];
                                break;
                            }
                        }
                        if(p==-1) fail[son[now][i]]=root;
                    }
                    Q.push(son[now][i]);
                }
            }
        }
    }
    int query(const string& s){
        int cnt=0;
        int p=root,q=-1;
        for(const auto&c:s){
            while(son[p][c-L]==-1&&p!=root){
                p=fail[p];
            }
            p=son[p][c-L];
            if(p==-1) p=root;
            for(q=p;q!=root&&end[q]!=-1;q=fail[q]){
                cnt+=end[q];
                end[q]=-1;
            }
        }
        return cnt;
    }
};