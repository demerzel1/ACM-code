template<typename T,int S> struct ST{
#define log2(i) 31-__builtin_clz(i)
static const int Dep=1+log2(SZ);
    T data[SZ];//[1,n]
    int dp[SZ][Dep];//最小值对应的下标
    void build(int n){
        for(int i=1;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<log2(n);j++)
            for(int i=1; i+(1<<(j+1))-1<=n; i++){
                if(data[dp[i][j]]<data[dp[i+(1<<j)][j]])
                    dp[i][j+1]=dp[i][j];
                else
                    dp[i][j+1]=dp[i+(1<<j)][j];
            }
    }
    int query(int a,int b){//查询[a,b]之间最小值的下标
        if(a>b) swap(a,b);
        int k=log2(b-a+1);
        if(data[dp[a][k]]<=data[dp[b-(1<<k)+1][k]])
            return dp[a][k];
        else
            return dp[b-(1<<k)+1][k];
    }
};