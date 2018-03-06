struct Matrix{
    int equ,var,k,col;
    bool a[MAXN][MAXN],x[MAXN];
    void set(int e,int v){equ=e,var=v;}
    void Get_Rank(){
        for(k=0,col=0;k<equ&&col<var;) {
            int r=k;
            for(int i=k;i<equ;i++)
                if(a[i][col]){r=i;break;}
            if(a[r][col]) {
                if(r!=k) for(int i=0;i<=var;i++) swap(a[r][i],a[k][i]);
                for(int i=k+1;i<equ;i++) if(a[i][col])
                    for(int j=k;j<=var;j++) a[i][j]^=a[k][j];
                k++;
            }
            col++;
        }
    }
    int solve(){
        Get_Rank();
        for(int i=k;i<equ;i++) if(a[i][col]) return -1;//无解
        if(k<var) return var-k;//自由变元有var-k个
        for (int i=var-1;i>=0;i--){
            x[i]=a[i][var];
            for(int j=i+1;j<var;j++) x[i]^=(a[i][j]&&x[j]);
        }
        return 0;
    }
}gao;