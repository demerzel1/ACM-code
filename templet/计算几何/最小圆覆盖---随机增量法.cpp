/*
	��СԲ���� ��������� BZOJ 1337
	��֤��ʱ�临�Ӷ� O(n)
	ƽ���ϸ������ɸ��㣬��һ����С��Բ������ȫ������ 
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
#define N 100001
#define eps 1e-9
using namespace std;
struct point{
	double x,y;
}p[N],O;
int n;
double R;
void swap(point &a,point &b){
	point t=a;a=b;b=t;
}
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
	}
	for(int i=1;i<=n;i++){
		swap(p[rand()%n+1],p[rand()%n+1]);
	}
}
void GetO_two(point a,point b,point &c){
	c.x=(a.x+b.x)/2;
	c.y=(a.y+b.y)/2;
	R=dist(a,b)/2;
}
point GetO_three(point A,point B,point C){//����ʹ�õ���еĶ�Ԫһ�η�������Բ�� 
	point ans;
	double A1,B1,C1,A2,B2,C2;
	A1=2*(A.x-B.x);B1=2*(A.y-B.y);C1=A.x*A.x+A.y*A.y-B.x*B.x-B.y*B.y;
	A2=2*(A.x-C.x);B2=2*(A.y-C.y);C2=A.x*A.x+A.y*A.y-C.x*C.x-C.y*C.y;
	//�õ�һ������ȥ���ڶ����������е�һ������ϵ��Ϊ0����� 
	if(fabs(A1)<eps){
		ans.y=C1/B1;ans.x=(C2-ans.y*B2)/A2;
	}else
	if(fabs(B1)<eps){
		ans.x=C1/A1;ans.y=(C2-ans.x*A2)/B2;
	}
	else{
		ans.x=(C2*B1-C1*B2)/(A2*B1-A1*B2);
		ans.y=(C2*A1-C1*A2)/(B2*A1-B1*A2);
	}
	return ans;
}
void solve(){
	O=p[1];R=0;
	for(int i=2;i<=n;i++){
		if(dist(p[i],O)<R+eps) continue;
		GetO_two(p[i],p[1],O);	
		for(int j=2;j<i;j++){
			if(dist(p[j],O)<R+eps) continue;
			GetO_two(p[i],p[j],O);
			for(int k=1;k<j;k++){
				if(dist(p[k],O)<R+eps) continue;
				O=GetO_three(p[i],p[k],p[j]);
				R=dist(O,p[i]);
			}
		}
	}
	printf("%.3lf\n",R);
}
int main(){
	srand(time(NULL));
	init();
	solve();
	return 0;
}

