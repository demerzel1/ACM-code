/*
	�������ճ�����  NOI2012��������
	һ����ʽ:��kԪ��(x1,x2,x3...xk)������g(x1,x2,x3...xk)=Eʱ����f(x1,x2,x3...xk)����ֵ 
		
	�������һ���������ճ���������ι����ģ�
�������⣺��g(x1, x2, x3, ..., xn) = c��Լ�������£���f(x1, x2, x3, ..., xn)����ֵ��
�������ǰ�������廯һ�£���g(x, y) = xy = 3��f(x, y) = x2 + y2 ����f(x, y)����Сֵ��
�������ǿ��Բµ���f(x, y)����Сֵ��6��
������Ϊf(x, y)ȡ����ֵʱ�ܵ�g(x, y)������Լ������ôf(x, y)�ķ�����Ӧ����g(x, y)�ķ�������ƽ�С�
�����������ǵõ�����ķ����飺
����fx = ��gx  ==> 2x = ��y
����fy = ��gy  ==> 2y = ��x
����g = 3      ==> xy = 3
������æ� = ��2 �����뷽������ (x, y) = (3^(1/2), 3^(1/2)) �� (x, y) = (-3^(1/2), -3^(1/2))

	����ɱ�ʾ��:
	f(v1,v2..vn) = sigma(si/vi)
	g(v1,v2..vn) = sigma(ki*si*(vi-vi')^2)-Eu=0
	������ƫ������Ԧ���ӣ��õ����·�����
	-s1 / v12 = 2��k1s1(v1-v1')
����-s2 / v22 = 2��k2s2(v2-v2')
����...
����-sn / vn2 = 2��knsn(vn-vn')
����g(v1,v2,v3...vn) = Eu

	���ѷ�������� ��һ�����Ǹ��������Ҧ����󣬸��ݦ�ȷ����vi��ʹ��g(v1,v2,v3...vn)����
	��ȻEu�������������
	��ô���Ƕ��֦ˣ�����g��Eu�Ĵ�С��ϵ���� 
	
	������vi,�����ȷ���Ժ󣬹����˹���vi��һԪ���η��̣����ǿ϶�ȡ���ұߵ��Ǹ����
	��һ�¸����ֵ�㣬����vi'���������������ۣ��ó��ұ߼�ֵ���ұߵĺ������ֵ����ԣ�֮����ܶ��ֽ���� 
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
using namespace std;
int n;
double K[N],S[N],V[N],Eu;
double GetV(int x,double nanda){
	double l=max(0.0,V[x]*2.0/3.0),r=1e8,mid;
	for(int i=1;i<=70;i++){
		mid=(l+r)*0.5;
		if(2*nanda*K[x]*mid*mid*mid-2*nanda*K[x]*V[x]*mid*mid+1>0) l=mid;
		else r=mid;  
	}
	return mid;
}
bool check(double nanda){
	double v,E=0;
	for(int i=1;i<=n;i++){
		v=GetV(i,nanda);
		E+=S[i]*K[i]*(v-V[i])*(v-V[i]);
	}
	return E<Eu;
}
int main(){
	double l,r,mid,ans=0;
	scanf("%d%lf",&n,&Eu);
	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&S[i],&K[i],&V[i]);
	l=-1e5;r=-1e-9;
	for(int i=1;i<=70;i++){
		mid=(l+r)*0.5;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(int i=1;i<=n;i++) ans+=S[i]/GetV(i,mid);
	printf("%.8lf\n",ans);
	return 0;
}

