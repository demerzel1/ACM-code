template<class T>
double romberg(const T&f,double a,double b,double eps=1e-6){
    vector<double>t;
    double h=b-a,last,curr,x,k1,k2,temp;
    int k=1,i=1;
    t.emplace_back(h*(f(a)+f(b))/2);
    do {
        last=t.back();
        curr=0;
        x=a+h/2;
        for(int j=0;j<k;++j) curr+=f(x),x+=h;
        curr=(t[0]+h*curr)/2;
        k1=4.0/3.0,k2=1.0/3.0;
        for(int j=0; j<i; j++) {
            temp=k1*curr-k2*t[j];
            t[j]=curr;   curr=temp;
            k2/=4*k1-k2; k1=k2+1;
        }
        t.emplace_back(curr);
        k*=2; h/=2; i++;
    }while(fabs(last-curr)>eps);
    return t.back();
}//调用romberg(f,a,b,eps),a是积分上界,b是积分下界;
double f(double x){
    return x*x; 
}//被积函数f
