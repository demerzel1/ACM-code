/*
	ģ���˻�  POJ 2420
	������һ����Ҳ��ȷ��һ���¶�T��Ȼ��ʼ��ͣ�ض�����ǰ��
	�����������½�����壬���ֻ�����ŵĵط�������ģ���˻�������ܶ�壬�����һ���������ŵĵط���Ծ
	����ȥdet��ʾ��Ծǰ��Ĳ�ֵdet<0
	�����������ȥ���ţ��Ǿ���
	������ţ�����e^(det/T) > random(0,1)������Ҳѡ����Ծ
	��Ȼ���ǰ�����С����T�Ƚϸ�ʱ�����������T�������ˣ��Ͳ���������
*/
#include<iostream>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 301
#define eps 1e-5
using namespace std;
struct point {
    double x,y;
} p[N],Ans,now;
int n;
double dist(point a,point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double calc(point A) {
    double res=0;
    for(int i=1; i<=n; i++)
        res+=dist(A,p[i]);
    return res;
}
void init() {
    for(int i=1; i<=n; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
}
void solve() {
    double X,Y,T=10000,preD,nextD;
    Ans.x=0;
    Ans.y=0;
    for(int i=1; i<=n; i++)
        Ans.x+=p[i].x,Ans.y+=p[i].y;
    Ans.x/=n;
    Ans.y/=n;
    while(T>eps) {
        preD=calc(Ans);
        X=0;
        Y=0;
        for(int i=1; i<=n; i++) {
            X+=(p[i].x-Ans.x)/dist(p[i],Ans);
            Y+=(p[i].y-Ans.y)/dist(p[i],Ans);
        }
        now.x=Ans.x+X*T;
        now.y=Ans.y+Y*T;
        nextD=calc(now);
        if(nextD<preD) Ans=now;
        else {
            double K=(double)(rand()%10001)/10000.00;
            if(exp((preD-nextD)/T)>K)
                Ans=now;
        }
        T*=0.95;
    }
    printf("%.0lf\n",calc(Ans));
}
int main() {
    srand(time(NULL));
    while(scanf("%d",&n)!=EOF) {
        init();
        solve();
    }
    return 0;
}

