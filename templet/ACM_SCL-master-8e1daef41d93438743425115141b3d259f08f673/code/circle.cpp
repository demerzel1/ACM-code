int CirCrossLine(cpoi a,cpoi b,cpoi o,ld r,Point* p){
    Point p1=a-o,d=b-a;
    ld A=d.len2(),B=2*dot(d,p1),C=p1.len2()-r*r;
    ld delta=B*B-4*A*C;
    if(!sgn(delta)){//相切
        ld t=-0.5*B/A;
        if(sgn(t-1)<=0&&sgn(t)>=0){
            p[0]=a+t*d;
            return 1;
        }
    }
    else if(~sgn(delta)){//相交
        ld t1=0.5*(-B-sqrt(delta))/A;
        ld t2=0.5*(-B+sqrt(delta))/A;
        int tlen=0;
        if(sgn(t1-1)<=0&&sgn(t1)>=0) p[tlen++]=a+t1*d;
        if(sgn(t2-1)<=0&&sgn(t2)>=0) p[tlen++]=a+t2*d;
        return tlen;
    }
    return 0;//相离
}//直线与圆，返回交点个数

//圆与多边形交的面积
ld Tri_area(cpoi a,cpoi b){
    return 0.5*fabs(det(a,b));
}
ld Sec_area(cpoi a,cpoi b,ld r){
    ld ang = atan2(a.y,a.x)-atan2(b.y,b.x) ;
    while (ang<=0)   ang+=2*pi;
    while (ang>2*pi) ang-=2*pi;
    return 0.5*r*r*min(ang,2*pi-ang);
}
ld calc(cpoi a,cpoi b,ld r){
    Point ti[2],O(0,0);
    int ina=sgn(a.len()-r),inb=sgn(b.len()-r);
    if (ina<0){
        if (inb<0) return Tri_area(a,b);
        else{
            CirCrossLine(a,b,O,r,ti);
            return Sec_area(b,ti[0],r)+Tri_area(a,ti[0]);
        }
    }
    else{
        int cnt=CirCrossLine(a,b,O,r,ti);
        if (inb<0)
            return Sec_area(a,ti[0],r)+Tri_area(b,ti[0]);
        else
            if(cnt==2){
                return Sec_area(a,ti[0],r)
                + Sec_area(b,ti[1],r)
                + Tri_area(ti[0],ti[1]);
            }
            else return Sec_area(a,b,r);
    }
}
ld Cir_Cross_Poly_Area(int n,Point *ps,cpoi o,ld r){
    ld res=0;
    ps[n]=ps[0];
    for (int i=0;i<n;i++){
        int tmp=sgn(det(ps[i]-o,ps[i+1]-o));
        if(tmp) res+=tmp*calc(ps[i]-o,ps[i+1]-o,r);
    }
    return fabs(res);
}
//圆与多边形交的面积
ld Cir_Cross_Cir_Area(cpoi o1,ld r1,cpoi o2,ld r2){
    ld d=(o1-o2).len();
    if(sgn(d-r1-r2)>=0) return 0;//相离、相切
    if(sgn(d-fabs(r1-r2))<=0){
        ld r3=min(r1,r2); return r3*r3*pi;
    }
    ld x=0.5*(d*d+r1*r1-r2*r2)/d;
    ld t1=acos(x/r1),t2=acos((d-x)/r2);
    return r1*r1*t1+r2*r2*t2-d*r1*sin(t1);
}//圆与圆交的面积