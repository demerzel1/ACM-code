const double pi=acos(-1.0);
const double eps=1e-8;
//double���͵������жϷ���
int cmp(double x){
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
//��ά���࣬�ɽ�����������
//����ƽ��
inline double sqr(double x){
    return x*x;
}
struct point{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b){
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b){
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b){
        return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b){
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b){
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b){
        return point(a.x/b,a.y/b);
    }
    double norm(){
        return sqrt(sqr(x)+sqr(y));
    }
};
//�����������
double det(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
//�����������
double dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
//�����������
double dist(const point &a,const point &b){
    return (a-b).norm();
}
//op��ԭ����ʱ����תA����
point rotate_point(const point &p,double A){
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}

const int maxn=100;
struct polygon{
    int n;
    point a[maxn];
    polygon(){}
    double area(){
        double sum=0;
        a[n]=a[0];
        for(int i=0;i<n;i++)
            sum+=det(a[i+1],a[i]);
        return sum/2.;
    }
    point MassCenter() {
        point ans=point(0,0);
        if(cmp(area())==0)
            return ans;
        a[n]=a[0];
        for(int i=0; i<n; i++)
            ans=ans+(a[i]+a[i+1])*det(a[i+1],a[i]);
        return ans/area()/6.;
    }
};



