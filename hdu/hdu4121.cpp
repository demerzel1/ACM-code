#include<bits/stdc++.h>
using namespace std;

typedef struct Point{
    int x;
    int y;
    Point(int xx=0,int yy=0){
        x=xx;
        y=yy;
    }
}point;
int x0,y0,n;
vector<point> v,r,h,c;
point g;
bool mp[15][15];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int hdx[]={1,-1,-2,-2,-1,1,2,2};
int hdy[]={-2,-2,-1,1,2,2,1,-1};
int hhx[]={0,0,-1,-1,0,0,1,1};
int hhy[]={-1,-1,0,0,1,1,0,0};
int cnt_n(int x1,int y1,int x2,int y2,int op){
    if(op==1){
        if(x1>x2)
            swap(x1,x2);
        int cnt=0;
        for(int i=x1+1;i<x2;i++){
            if(mp[i][y1])
                cnt++;
        }
        return cnt;
    }else{
        if(y1>y2)
            swap(y1,y2);
        int cnt=0;
        for(int i=y1+1;i<y2;i++){
            if(mp[x1][i])
                cnt++;
        }
        return cnt;
    }
}

bool judge_g(int tx,int ty){
    if(ty==g.y){
        if(cnt_n(g.x,g.y,tx,ty,1)==0)
            return true;
    }
    return false;
}

bool judge_r(int tx,int ty){
    for(int i=0;i<r.size();i++){
        if(r[i].x==tx&&r[i].y==ty)
            continue;
        if(r[i].x==tx){
            if(cnt_n(r[i].x,r[i].y,tx,ty,2)==0)
                return true;
        }
        if(r[i].y==ty){
            if(cnt_n(r[i].x,r[i].y,tx,ty,1)==0)
                return true;
        }
    }
    return false;
}

bool judge_c(int tx,int ty){
    for(int i=0;i<c.size();i++){
        if(c[i].x==tx&&c[i].y==ty)
            continue;
        if(c[i].x==tx){
            if(cnt_n(c[i].x,c[i].y,tx,ty,2)==1)
                return true;
        }
        else if(c[i].y==ty){
            if(cnt_n(c[i].x,c[i].y,tx,ty,1)==1)
                return true;
        }
    }
    return false;
}

bool judge_h(int tx,int ty){
    for(int i=0;i<h.size();i++){
        for(int j=0;j<8;j++){
            int thx=h[i].x+hdx[j];
            int thy=h[i].y+hdy[j];
            if(tx==thx&&ty==thy){
                int thhx=h[i].x+hhx[j];
                int thhy=h[i].y+hhy[j];
                if(!mp[thhx][thhy])
                    return true;
            }
        }
    }
    return false;
}

bool judge(int tx,int ty){
    if(judge_c(tx,ty)||judge_g(tx,ty)||judge_h(tx,ty)||judge_r(tx,ty))
        return true;
    return false;
}

int main(){
    while(cin>>n>>x0>>y0){
        if(n==0&&x0==0&&y0==0)
            break;
        memset(mp,false,sizeof(mp));
        c.clear();
        h.clear();
        r.clear();
        for(int i=0;i<n;i++){
            char cc;
            int aa,bb;
            cin>>cc>>aa>>bb;
            if(cc=='G')
                g=point(aa,bb);
            if(cc=='H')
                h.push_back(point(aa,bb));
            if(cc=='R')
                r.push_back(point(aa,bb));
            if(cc=='C')
                c.push_back(point(aa,bb));
            mp[aa][bb]=true;
        }
        bool flag=true;
        for(int i=0;i<4;i++){
            int tx=x0+dx[i];
            int ty=y0+dy[i];
            if(tx>=1&&tx<=3&&ty>=4&&ty<=6){
                if(!judge(tx,ty)){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
