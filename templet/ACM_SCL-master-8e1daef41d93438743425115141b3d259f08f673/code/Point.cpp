#define cpoi const Point&
typedef double ld;
const ld pi=acos(-1);
const ld EPS=1e-6;
inline int sgn(ld a){return a<-EPS?-1:a>EPS;}

struct Point{
    ld x,y;
    Point(){}
    Point(ld a,ld b):x(a),y(b){}
    bool operator<(cpoi p)const{
        int c=sgn(x-p.x);
        if(c){return c==-1;}
        return sgn(y-p.y)==-1;
    }
    Point operator+(cpoi p)const{return Point(x+p.x,y+p.y);}
    Point operator-(cpoi p)const{return Point(x-p.x,y-p.y);}
    Point operator*(ld d)const{return Point(x*d,y*d);}
    Point operator/(ld d)const{return Point(x/d,y/d);}
    ld len2()const{return x*x+y*y;}
    ld len()const {return sqrt(len2());}
    Point unit()const{return *this/len();}
    void read() {cin>>x>>y;}
    void write(){cout<<"("<<x<<","<<y<<")"<<endl;}
    Point rot(const ld &t, Point o=Point(0,0))const{
        ld dx=x-o.x,dy=y-o.y;
        ld nx=cos(t)*dx + sin(t)*dy;
        ld ny =-sin(t)*dx + cos(t)*dy;
        return Point(nx,ny)+o;
    }//以o为中心,顺时针方向旋转t
    Point rot90()const{return Point(-y,x);}//逆时针方向旋转90
};

Point operator*(ld d,cpoi a) {return Point(a.x*d,a.y*d);}
ld det(cpoi a,cpoi b){return a.x*b.y-a.y*b.x;}
ld dot(cpoi a,cpoi b){return a.x*b.x+a.y*b.y;}
#define cross(o,a,b) det((a)-(o),(b)-(o))
#define crossOp(o,a,b) sgn(cross(o,a,b))

bool ParaLL(cpoi a,cpoi b){
    return !sgn(det(a,b));
}//向量平行
bool PointonSeg(cpoi p,cpoi s,cpoi t){
    return ParaLL(p-s,t-s) && sgn(dot(p-s,p-t))<=0;
}//点p是否在线段s-t之间
bool on_seg(cpoi p,cpoi s,cpoi t){
    return PointonSeg(p,s,t) && sgn(cross(s,t,p))<=0;
}//c是否在线段ab上
Point isLL(cpoi s1,cpoi t1,cpoi s2,cpoi t2){
    ld a1=cross(s2,t2,s1), a2=-cross(s2,t2,t1);
    return (s1*a2 + t1*a1)/(a1+a2);
}//直线s1-t1,s2-t2交点
bool IsSegCross(cpoi s1,cpoi t1,cpoi s2,cpoi t2){
    return
    max(s1.x,t1.x) >= min(s2.x,t2.x) &&
    max(s2.x,t2.x) >= min(s1.x,t1.x) &&
    max(s1.y,t1.y) >= min(s2.y,t2.y) &&
    max(s2.y,t2.y) >= min(s1.y,t1.y) &&
    sgn(det(s2-t1,s1-t1))*sgn(det(t2-t1,s1-t1))<= 0 &&
    sgn(det(s1-t2,s2-t2))*sgn(det(t1-t2,s2-t2))<= 0;
}//判断线段s1-t1是否与s2-t2有交点
Point Proj(cpoi p,cpoi s,cpoi t){
    return s+(t-s)*(dot(p-s,t-s)/(t-s).len2());
}//p在直线s-t上的投影
ld P2Line(cpoi p,cpoi s,cpoi t){
    return fabs(det(p-s,t-s))/(t-s).len();
}//点到直线距离
ld P2Seg(cpoi p,cpoi s,cpoi t){
    if (sgn(dot(p-s,t-s))<=0)return (p-s).len();
    if (sgn(dot(p-t,s-t))<=0)return (p-t).len();
    return fabs(det(s-p,t-p))/(s-t).len();
}//点p到线段s-t距离
Point P2P_sym(cpoi p,cpoi q){
    return p+p-q;
}//q关于p的中心对称点
Point P2L_sym(cpoi p,cpoi s,cpoi t){
    return P2P_sym(Proj(p,s,t),p);
}//p关于直线s-t的对称点