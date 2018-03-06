struct Phalf{
    Point s,t;
    ld ang;
    Phalf(){}
    Phalf(const Point&p,const Point&q):s(p),t(q){
        ang=atan2(q.y-p.y,q.x-p.x);
    }//s->t向量的左边(逆时针方向)
    void read(){
        s.read(),t.read();
        ang=atan2(t.y-s.y,t.x-s.x);
    }
    bool operator <(const Phalf&p)const{
        int c=sgn(ang-p.ang);
        return c==0?crossOp(p.s,p.t,s)>=0:c==1;
    }
    bool operator ==(const Phalf&p)const{
        return sgn(ang-p.ang)==0;
    }
};
//isLL
vector<Point> convexCut(const vector<Point>&ps,const Phalf&ph){
    vector<Point> qs;
    int n=ps.size();
    for(int i=0; i<n; i++){
        Point p1=ps[i], p2=ps[(i+1)%n];
        int d1=crossOp(ph.s,ph.t,p1), d2=crossOp(ph.s,ph.t,p2);
        if(d1>=0)   qs.push_back(p1);
        if(d1*d2<0) qs.push_back(isLL(p1,p2,ph.s,ph.t));
    }
    return qs;
}//用半平面ph的逆时针方向去切凸多边形，log n

//半平面交,nlogn,点必须逆时针
void init_Phalf(ld inf,vector<Point>& ps){
    ps.clear();
    ps.push_back(Point(-inf,-inf));
    ps.push_back(Point(inf,-inf));
    ps.push_back(Point(inf,inf));
    ps.push_back(Point(-inf,inf));
}
void gao_Phalf(int n,Point *ps,vector<Point>&qs){
    for(int i=0;i<n;i++){
        qs=convexCut(qs,Phalf(ps[i],ps[(i+1)%n]));
    }
}
//半平面交,nlogn,点必须逆时针

//半平面交,nlogn,点可无序
Phalf que[MAXN];
int qh, qt;
bool check(const Phalf&a,const Phalf&b,const Phalf&me){
    return crossOp(me.s,me.t,isLL(a.s,a.t,b.s,b.t))>0;
}
void Phalf_Intersection(int n,Phalf *ps,vector<Point>&qs) {
    qh=qt=0;qs.clear();
    sort(ps,ps+n);
    n=unique(ps,ps+n)-ps;
    for(int i=0; i<n; i++){
        Phalf u=ps[i];
        while (qh+1<qt && !check(que[qt-2],que[qt-1],u))
            --qt;
        while (qh+1<qt && !check(que[qh],que[qh+1],u))
            ++qh;
        que[qt++]=u;
    }
    while (qh+1<qt && !check(que[qt-2],que[qt-1],que[qh]))
        --qt;
    while (qh+1<qt && !check(que[qh],que[qh+1],que[qt-1]))
        ++qh;
    for (int i=qh; i < qt; i++){
        int nxt= i+1==qt? qh : i+1;
        qs.push_back(isLL(que[i].s,que[i].t,que[nxt].s,que[nxt].t));
    }
}
//半平面交,nlogn
//多边形的核：多边形的所有边的左半平面的交集.