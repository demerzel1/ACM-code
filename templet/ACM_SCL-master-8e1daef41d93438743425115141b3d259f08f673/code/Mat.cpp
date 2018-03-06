template <typename T,int n> struct Mat{
    T a[n][n];
    Mat(){memset(a,0,sizeof(a));}
    void unit(){
        for(int i=0;i<n;i++)a[i][i]=1;
    }
    Mat& operator*=(const Mat<T,n>&b){
        Mat<T,n> t;
        for(int i=0;i<n;i++)
            for(int k=0;k<n;k++) 
                if(a[i][k])for(int j=0;j<n;j++){
                    t.a[i][j]+=a[i][k]*b.a[k][j];
                }
        *this=t; return *this;
    }
    Mat pow(ll k)const{
        Mat<T,n> r,p=*this;
        r.unit();
        for(;k;k>>=1,p*=p) if(k&1) r*=p;
        return r;
    }
};