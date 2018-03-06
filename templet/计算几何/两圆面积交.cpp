const ld PI=acos(-1.0);

ld Area(ld x1,ld y1,ld r1,ld x2,ld y2,ld r2) {
    ld d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    if(d>=(r1+r2)*(r1+r2))
        return 0;
    else if((r1-r2)*(r1-r2)>=d) {
        if(r1>r2)
            return PI*r2*r2;
        else
            return PI*r1*r1;
    } else {
        ld a1=2*acosl((r1*r1+d-r2*r2)/2/r1/sqrt(d));
        ld a2=2*acosl((r2*r2+d-r1*r1)/2/r2/sqrt(d));
        ld ans=r1*r1*a1/2+r2*r2*a2/2-r1*r1*sinl(a1)/2-r2*r2*sinl(a2)/2;
        return ans;
    }
}
