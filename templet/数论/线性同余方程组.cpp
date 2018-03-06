/*
	����ͬ�෽���� 
	n % A1 = B1
	n % A2 = B2 ....
	n % An = Bn
	��n����С�������� 
*/
/*
	1���й�ʣ�ඨ�� 
	��A1,A2,A3...An���ʵ�ʱ�򣬿���ʹ��
	����ÿ������ i����� k��ʹ�� k�ǳ���Ai���⣬����A����С��������Ȼ����k ����Ai����Ԫ
	�õ� p,�� p % Ai = 1 �� p�ǳ���Ai���⣬����A�Ĺ�����
	���n = p1*B1 + p2*B2 + ... + pn*Bn 
*/
/*
	2������A�����ʵ���� POJ 2891
	�������ǲ���һ�ֲ��Ϻϲ��������̵�һ��ⷨ
	��ֻʣ���һ�����̵�ʱ�򣬴�Ҳ�ͳ�����
	����Ҫ�ϲ�:
	n % A1 = B1
	n % A2 = B2
	��
	n=A1*x+B1=A2*y+B2
	���� A1*x+A2*y=B2-B1
	��d=gcd(A1,A2)
	��� (B2-B1)%d!=0 ���޽�
	a=A1/d;b=A2/d;c=(B2-B1)/d; 
	��exgcd���x (x'=((x*c)%b+b)%b;)
	��ʱ n=A1*X+B1 ,X=x'+k*b (kΪ����)
	���µķ��̿ɿ��� n=A1*x'+A1*b*k+B1 -> n % A1*b = B1+A1*x' 
	��ֻʣһ������ʱ��n=B 
	�������£� 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(!b){
		x=1;y=0;return a;
	}
	long long d=exgcd(b,a%b,x,y),t=x;
	x=y;y=t-a/b*y;
	return d;
}
int n;
void solve(){
	long long x,y,a,b,c,d,A1,A2,B1,B2;
	bool noans=0;
	cin>>A1>>B1;
	for(int i=2;i<=n;i++){
		cin>>A2>>B2;
		if(noans) continue;
		d=exgcd(A1,A2,x,y);
		if((B2-B1)%d!=0){
			noans=1;continue;
		}
		a=A1/d;b=A2/d;c=(B2-B1)/d;
		exgcd(a,b,x,y);
		x=((x*c)%b+b)%b;
		B1=(B1+A1*x)%(A1*b);A1=A1*b;
	}
	if(noans) cout<<-1<<endl;
	else cout<<B1<<endl;
} 
int main(){
	while(scanf("%d",&n)!=EOF){
		solve();
	}
	return 0;
}

