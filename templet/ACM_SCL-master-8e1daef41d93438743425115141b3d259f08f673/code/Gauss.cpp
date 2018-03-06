const double EPS=1e-6;
template<typename T>T gcd(T a,T b){
    if(!a)return 1;if(!b)return a;
    if(a<0) a=-a; for (T t;b;t=a%b,a=b,b=t);
    return a;
}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> struct Gauss{
    int equ,var,k,col;
    T a[MAXN][MAXN],x[MAXN],temp;
    void set(int e,int v){equ=e,var=v;}
    int sgn(T);
    void upmaxr(int,int&);
    void update(int);
    void Get_Rank(){
        for(k=0,col=0;k<equ&&col<var;k++,col++){
            int maxr=k;
            for(int i=k+1;i<equ;i++) upmaxr(i,maxr);
            if(maxr!=k) for(int j=k;j<var+1;j++) swap(a[k][j],a[maxr][j]);
            if(!sgn(a[k][col])){k--;continue;}
            for(int i=k+1;i<equ;i++) if(sgn(a[i][col])) update(i);
        }
    }
    int solve(){
        Get_Rank();
        for(int i=k;i<equ;i++) if(sgn(a[i][col])) return -1;//无解
        if(k<var) return var-k;//自由变元有var-k个
        for (int i=var-1;i>=0;i--){
            temp=a[i][var];
            for(int j=i+1;j<var;j++) if(sgn(a[i][j])) temp-=a[i][j]*x[j];
            x[i]=temp/a[i][i];
        }
        return 0;
    }
};
template<>int Gauss<double>::sgn(double p){return p<-EPS? -1:p>EPS;}
template<>int Gauss<int>::sgn(int p){return p!=0;}
template<>int Gauss<mint>::sgn(mint p){return p.x!=0;}

template<>void Gauss<double>::upmaxr(int i,int &maxr){if(fabs(a[i][col])>fabs(a[maxr][col])) maxr=i;}
template<>void Gauss<int>::upmaxr(int i,int &maxr){if(abs(a[i][col])>abs(a[maxr][col])) maxr=i;}
template<>void Gauss<mint>::upmaxr(int i,int &maxr){if(a[i][col].x>a[maxr][col].x) maxr=i;}

template<>void Gauss<double>::update(int i){
    temp=a[i][col]/a[k][col];
    for(int j=col;j<var+1;j++) a[i][j]-=a[k][j]*temp;
}
template<>void Gauss<int>::update(int i){
    int L=lcm(abs(a[i][col]),abs(a[k][col]));
    int ta=L/abs(a[i][col]),tb=L/abs(a[k][col]);
    if(a[i][col]*a[k][col]<0) tb=-tb;
    for(int j=col;j<var+1;j++) a[i][j]=a[i][j]*ta-a[k][j]*tb;
}
template<>void Gauss<mint>::update(int i){
    mint L=lcm(a[i][col].x,a[k][col].x);
    mint ta=L/a[i][col],tb=L/a[k][col];
    if((a[i][col]*a[k][col]).x<0) tb=-tb;
    for(int j=col;j<var+1;j++) a[i][j]=a[i][j]*ta-a[k][j]*tb;
}