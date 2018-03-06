/*
	��ɽ��  BZOJ 3680
	���ó�ʼ�¶�T��һ��ʼ�¶Ⱥܸߣ���Ӧ�ܾ��ң��𰸵ı䶯���Ƚϴ�
	�����¶Ƚ������Ժ󣬷�Ӧ�������𰸱䶯���ȼ�С�������һ�������ڹ̶���һ������ 
*/
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 10001
#define eps 1e-9
using namespace std;
struct point{
	double x,y,w;
}p[N],ans;
int n;
inline double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].w);
		ans.x+=p[i].x*p[i].w;ans.y+=p[i].y*p[i].w;
	}
	ans.x/=n;ans.y/=n;
	double T=200000,X,Y;
	while(T>eps){
		X=0;Y=0;
		for(int i=1;i<=n;i++){
			X+=(p[i].x-ans.x)*p[i].w/dist(p[i],ans);
			Y+=(p[i].y-ans.y)*p[i].w/dist(p[i],ans);
		}
		ans.x+=X*T;ans.y+=Y*T;
		T*=0.97;
	}
	printf("%.3lf %.3lf\n",ans.x,ans.y);
	return 0;
}

