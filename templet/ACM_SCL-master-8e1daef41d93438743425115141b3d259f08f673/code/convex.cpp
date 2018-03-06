int Point_in(int n,Point *poly,cpoi p){
    int cnt=0,d1,d2,k;
    poly[n]=poly[0];
    for(int i=0;i<n;i++){
        if(PointonSeg(p,poly[i],poly[i+1])) return -1;
        k=sgn(det(poly[i+1]-poly[i],p-poly[i]));
        d1=sgn(poly[i].y-p.y);
        d2=sgn(poly[i+1].y-p.y);
        if(k>0&&d1<=0&&d2>0)++cnt;
        if(k<0&&d2<=0&&d1>0)--cnt;
    }
    return cnt!=0;
}//点与多边形，内=1，外=0，边上=-1
ld PolyArea(const vector<Point>&ps) {
    int n=ps.size();if(n<3) return 0;
    ld ret=0;
    for (int i=0; i<n; i++)
        ret+=det(ps[i],ps[(i+1)%n]);
    return fabs(0.5*ret);
}//多边形面积,点必须顺/逆时针
Point Mass_Center(const vector<Point> &ps){
    ld s=0,t;
    Point ret(0,0);
    int n=ps.size();
    for(int i=2;i<n;i++){
        t=cross(ps[0],ps[i-1],ps[i]);
        s+=t;
        ret=ret+t*(ps[0]+ps[i-1]+ps[i]);
    }
    return ret/s/3.0;
}//多边形重心,点必须顺/逆时针

void convexHull(vector<Point>&ps,vector<Point>&qs) {
    int n=ps.size();
    if (n<=1){qs=ps;return;}
    qs.clear();
    sort(ps.begin(), ps.end());
    for (int i=0; i<n; qs.push_back(ps[i++])){
        while(qs.size()>1&&crossOp(qs[qs.size()-2],qs.back(),ps[i])<=0)
            qs.pop_back();
    }
    for(int i=n-2,t=qs.size();i>=0; qs.push_back(ps[i--])){
        while(qs.size()>t&&crossOp(qs[qs.size()-2],qs.back(),ps[i])<=0)
            qs.pop_back();
    }
    qs.pop_back();
}//计算凸包,ps是多边形，qs是凸包
ld convexDiameter(const vector<Point>&ps) {
    int n=ps.size(),is=0,js=0;
    for (int i=1; i<n; ++i){
        if (ps[i].x>ps[is].x) is=i;
        if (ps[i].x<ps[js].x) js=i;
    }
    ld maxd=(ps[is]-ps[js]).len2();
    int i=is,j=js;
    do{
        if(det(ps[(i+1)%n]-ps[i],ps[(j+1)%n]-ps[j])<0)
            (++i) %=n;
        else
            (++j)%=n;
        maxd=max(maxd,(ps[i]-ps[j]).len2());
    }while(i!=is||j!=js);
    return maxd;
}//凸包最远点对距离
void convexCut(const vector<Point>&ps,vector<Point>&qs,cpoi q1,cpoi q2){
    qs.clear();
    int n=ps.size();
    for(int i=0; i<n; i++){
        Point p1=ps[i], p2=ps[(i+1)%n];
        int d1=crossOp(q1,q2,p1), d2=crossOp(q1,q2,p2);
        if(d1>=0)   qs.push_back(p1);
        if(d1*d2<0) qs.push_back(isLL(p1,p2,q1,q2));
    }
}// 用半平面 (q1,q2) 的逆时针方向去切凸多边形
int PointInConvex(const vector<Point>&ps,cpoi b){
    int n=ps.size();
    Point g=(ps[0]+ps[n/3]+ps[2*n/3])/3.0;
    int l=0,r=n;
    while (l+1<r) {
        int mid=(l+r)/2;
        if(sgn(det(ps[l]-g,ps[mid]-g)>0)){
            if(sgn(det(ps[l]-g,b-g))>=0&&sgn(det(ps[mid]-g,b-g))<0)
                r=mid;
            else l=mid;
        }
        else{
            if(sgn(det(ps[l]-g,b-g))<0&&sgn(det(ps[mid]-g,b-g))>=0)
                l=mid;
            else r=mid;
        }
    }
    r%=n;
    int z=sgn(det(ps[r]-b,ps[l]-b))-1;
    if(z==-2){return 1;}
    return z;
}//点是否在凸包内,1.内，-1.边上，0.外,O(log n)