#define cpoi const Point&
typedef double ld;
const ld pi=acos(-1);
const ld EPS=1e-8;
inline int sgn(ld a) {return a<-EPS? -1:a>EPS;}
struct Point{
    ld x,y,z;
    Point(){}
    Point(ld _x,ld _y,ld _z):x(_x),y(_y),z(_z){}
    ld len2()const{return x*x+y*y+z*z;}
    ld len()const {return sqrt(len2());}
    void read() {scanf("%lf%lf%lf",&x,&y,&z);}
    void write() {cout<<"("<<x<<","<<y<<","<<z<<")"<<'\n';}
};
Point operator+(cpoi a,cpoi b) {
    return Point(a.x+b.x,a.y+b.y,a.z+b.z);}
Point operator-(cpoi a,cpoi b) {
    return Point(a.x-b.x,a.y-b.y,a.z-b.z);}
Point operator*(cpoi p,ld d) {
    return Point(p.x*d,p.y*d,p.z*d);}
Point operator*(ld d,cpoi p) {
    return Point(p.x*d,p.y*d,p.z*d);}
Point operator/(cpoi p,ld d) {
    return Point(p.x/d,p.y/d,p.z/d);}
Point det(cpoi a,cpoi b){
    return Point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
ld dot(cpoi a,cpoi b){
    return a.x*b.x+a.y*b.y+a.z*b.z;}
bool PerPeD(cpoi a,cpoi b){
    return !sgn(dot(a,b));}//向量垂直
bool ParaLL(cpoi a,cpoi b){
    return det(a,b).len2()<EPS;}//向量平行
ld ang_cos(cpoi a,cpoi b){
    return dot(a,b)/(a.len()*b.len());}//向量夹角cos
Point pvec(cpoi a,cpoi b,cpoi c){
    return det(a-b,b-c);}//平面法向量
bool P3_coline(cpoi a,cpoi b,cpoi c){
    return ParaLL(a-b,b-c);}//三点共线
bool P4_coplane(cpoi a,cpoi b,cpoi c,cpoi d){//四点共面
    if(P3_coline(a,b,c)) return false;
    return PerPeD(pvec(a,b,c),d-a);}
ld P2Line(cpoi p,cpoi l1,cpoi l2){
    return det(p-l1,l2-l1).len()/(l2-l1).len();
}//点到直线距离
ld P2Seg(cpoi p,cpoi l1,cpoi l2){
    if(l1==l2) return (p-l1).len();// need ==
    Point v1=l2-l1,v2=p-l1,v3=p-l2;
    if(dot(v1,v2)<0)return v2.len();
    if(dot(v1,v3)>0)return v3.len();
    return det(v1,v2).len()/v1.len();
}//点到线段距离
ld P2Plane(cpoi p,cpoi s1,cpoi s2,cpoi s3){
    Point n=pvec(s1,s2,s3);
    return fabs(dot(n,p-s1))/n.len();
}//点到平面距离
bool P_InTri(cpoi p,cpoi s1,cpoi s2,cpoi s3){
    assert(!P3_coline(s1,s2,s3));
    return !sgn(det(s1-s2,s1-s3).len()-det(p-s1,p-s2).len()-
                det(p-s2,p-s3).len()-det(p-s3,p-s1).len());
}//判点是否在空间三角形内(不包含边界,否则需再判断点是否与某条边共线)

struct Line{
    Point a,b;
    Line(){}
    Line(cpoi _a,cpoi _b):a(_a),b(_b){}
    ld P2Line(cpoi p)const{
        return det(p-a,b-a).len()/(b-a).len();}//点到直线距离
    Line PerPeD(cpoi p)const{
        return Line(p,det(det(b-a,a-p),b-a));}//点到直线垂线
};
bool ParaLL(const Line& u,const Line& v){
    return ParaLL(u.a-u.b,v.a-v.b);}//判两直线平行
bool PerPeD(const Line& u,const Line& v){
    return PerPeD(u.a-u.b,v.a-v.b);}//判两直线垂直
ld angle_cos(const Line& u,const Line& v){
    return ang_cos(u.a-u.b,v.a-v.b);}//线线角cos
int same_side(cpoi p1,cpoi p2,const Line& l){
    if(!P4_coplane(p1,p2,l.a,l.b)) return -2;
    return sgn(dot(det(l.a-l.b,p1-l.b),det(l.a-l.b,p2-l.b)));
}//判两点在线段同侧=1,异侧=-1,在线段上=0,不共面-2
ld L2Line(const Line& u,const Line& v,Point& n){
    n=det(u.a-u.b,v.a-v.b);
    if(n.len2()<EPS) return u.P2Line(v.a);//平行直线距离
    return fabs(dot(u.a-v.a,n))/n.len();//不平行直线最近距离
}//直线到直线距离
bool onSegIn(cpoi p,const Line& l){
    return P3_coline(p,l.a,l.b)&&
    (l.a.x-p.x)*(l.b.x-p.x)<EPS&&
    (l.a.y-p.y)*(l.b.y-p.y)<EPS&&
    (l.a.z-p.z)*(l.b.z-p.z)<EPS;
}//判点是否在线段上,含端点
bool SegCrossIn(const Line& u,const Line& v){
    if(!P4_coplane(u.a,u.b,v.a,v.b)) return false;
    if (!P3_coline(u.a,u.b,v.a)||!P3_coline(u.a,u.b,v.b))
        return same_side(u.a,u.b,v)<1&&same_side(v.a,v.b,u)<1;
    return onSegIn(u.a,v)||onSegIn(u.b,v)||
    onSegIn(v.a,u)||onSegIn(v.b,u);
}//判两线段相交,包括端点和部分重合
bool SegCrossEx(const Line& u,const Line& v){
    return same_side(u.a,u.b,v)==-1&&same_side(v.a,v.b,u)==-1;
}//判两线段相交,不包括端点和部分重合
bool isLL(cpoi u1,cpoi u2,cpoi v1,cpoi v2,Point& ret){
    if(!P4_coplane(u1,u2,v1,v2)||
       ParaLL(Line(u1,u2),Line(v1,v2))) return false;
    ld t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
    /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret=u1+(u2-u1)*t;return true;
}//两直线交点,线段交点请另外判线段相交

struct Plane{
    Point a,b,c;
    Plane(){}
    Plane(cpoi _a,cpoi _b,cpoi _c):
    a(_a),b(_b),c(_c){assert(!P3_coline(a,b,c));}
    
    Point pvec()const{return det(a-b,b-c);}//平面法向量
    ld P2Plane(cpoi p)const{
        Point n=pvec();
        return fabs(dot(n,p-a))/n.len();
    }//点到平面距离
};
bool ParaLL(const Plane& u,const Plane& v){
    return ParaLL(u.pvec(),v.pvec());}//判两平面平行
bool PerPeD(const Plane& u,const Plane& v){
    return PerPeD(u.pvec(),v.pvec());}//判两平面垂直
ld angle_cos(const Plane& u,const Plane& v){
    return ang_cos(u.pvec(),v.pvec());}//面面角cos
bool ParaLL(const Line& l,const Plane& s){
    return PerPeD(s.pvec(),l.a-l.b);}//判直线与平面平行
bool PerPeD(const Line& l,const Plane& s){
    return ParaLL(s.pvec(),l.a-l.b);}//判直线与平面垂直
ld angle_sin(const Line& l,const Plane& s){
    return ang_cos(l.a-l.b,s.pvec());}//线面角sin
int same_side(cpoi p1,cpoi p2,const Plane& s){
    Point n=s.pvec();
    return sgn(dot(n,p1-s.a)*dot(n,p2-s.a));
}//判两点在平面同侧=1,异侧=-1,在平面上=0
bool SegCrossTriIn(const Line& l,const Plane& s){
    return same_side(l.a,l.b,s)<1
    &&same_side(s.a,s.b,Plane(l.a,l.b,s.c))<1
    &&same_side(s.b,s.c,Plane(l.a,l.b,s.a))<1
    &&same_side(s.c,s.a,Plane(l.a,l.b,s.b))<1;
}//判线段与空间三角形相交,包括交于边界和(部分)包含
bool SegCrossTriEx(const Line& l,const Plane& s){
    return same_side(l.a,l.b,s)==-1
    &&same_side(s.a,s.b,Plane(l.a,l.b,s.c))==-1
    &&same_side(s.b,s.c,Plane(l.a,l.b,s.a))==-1
    &&same_side(s.c,s.a,Plane(l.a,l.b,s.b))==-1;
}//判线段与空间三角形相交,不包括交于边界和(部分)包含
bool isPoPL(cpoi l1,cpoi l2,cpoi s1,cpoi s2,cpoi s3,Point& ret){
    if(ParaLL(Line(l1,l2),Plane(s1,s2,s3))) return false;
    ret=pvec(s1,s2,s3);
    ld t=dot(ret,s1-l1)/dot(ret,l2-l1);
    ret=l1+(l2-l1)*t;return true;
}//直线平面交点,线段和空间三角形交点请另外判断
bool isPLPL(const Plane& u,const Plane& v,Line& ret){
    if(ParaLL(u,v)) return false;
    ParaLL(Line(v.a,v.b),u)?isPoPL(v.b,v.c,u.a,u.b,u.c,ret.a):
    isPoPL(v.a,v.b,u.a,u.b,u.c,ret.a);
    ParaLL(Line(v.c,v.a),u)?isPoPL(v.b,v.c,u.a,u.b,u.c,ret.b):
    isPoPL(v.c,v.a,u.a,u.b,u.c,ret.b);
    return true;
}//计算两平面交线,注意事先判断是否平行,并保证三点不共线!
