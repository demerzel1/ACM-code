/*
	���㼸�β���ģ�����
	ʵ�������������Ϊ���� ÿ������ֻд1~2������ 
*/
#define eps 1e-9
struct point(){
	double x,y;
};

//��ƽ�������ľ���
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//�������
point operator -(const point &a,const point &b){
	point c;c.x=a.x-b.x;c.y=a.y-b.y;
	return c;
}

//�������
double operator *(const point &a,const point &b){
	return a.y*b.x-a.x*b.y;
}

//�������  ע�⣺�˴�����������ͬ���������޸� 
double operator *(const point &a,const point &b){
	return a.x*b.x+a.y*b.y;
}

//�ж� A -> B -> C�Ĺ��䷽��  =0 ���ߣ�<0 ����>0 ����  
double Turnto(point A,point B,point C){
	return (C-A)*(B-A); 
}

/*�жϵ��Ƿ����߶���
1���ж����Ƿ��ڸ��߶����ڵ�ֱ����(�õ�ָ���߶������˵����������)
2���жϸõ�ָ���߶������˵����������Ƿ��Ǹ��� 
*/

//�ж������߶��Ƿ��ཻ 
struct line{
	point a,b;
};
bool quick_check(line A,line B){ //���ο����ų�
	if(max(A.a.x,A.b.x)<min(B.a.x,B.b.x) ||
	min(A.a.x,A.b.x)>max(B.a.x,B.b.x) ||
	max(A.a.y,A.b.y)<min(B.a.y,B.b.y) ||
	min(A.a.y,A.b.y)>max(B.a.y,B.b.y)) return 0;
	else return 1; 
}
bool isInter(line A,line B){ //0:�����߶β��ཻ 1:�ཻ 
	if(!quick_check(A,B)) return 0;
	if(Turnto(A.a,A.b,B.a)*Turnto(A.a,A.b,B.b)<eps && 
	Turnto(B.a,B.b,A.a)*Turnto(B.a,B.b,A.b)<eps) return 1;
	else return 0;  
}

//�ж��߶��Ƿ���ֱ���ཻ��ֻ��ֱ���Ƿ�����߶μ���
bool isInter(line A,line B){ // AΪֱ�� BΪ�߶� 
	if(Turnto(A.a,A.b,B.a)*Turnto(A.a,A.b,B.b)<eps) return 1;
	else return 0;
}

//�ж�����ֱ���Ƿ��ཻ��ֻҪ�ж��ǲ���ƽ�еľͺ�(�غϸ����������)
bool isInter(line A,line B){//A,B��Ϊֱ��
	if(fabs((A.a-A.b)*(B.a-B.b))<eps) return 0;
	else return 1; 
}

//������ֱ�ߵĽ���
point Get_InterPoint(line A,line B){
	double k1,k2,k3;point Ans;
	k1=(A.b-A.a)*(B.a-A.a);
	k2=(B.b-A.a)*(A.b-A.a);
	k3=k1/(k1+k2);
	Ans.x=B.a.x+(B.b.x-B.a.x)*k3;
	Ans.y=B.a.y+(B.b.y-B.a.y)*k3;
	return Ans;
}

//����һ�������˵㶼��������߶Σ����߶��ϳ��˶˵�������� on = gcd(detX,detY)-1
//����һ���������ε�ÿ�����㣨˳ʱ�����ʱ��˳�򣩣�����߽��ϵ�������
int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
} 
int getOn(int tot,const point P[]){//tot:������ P����һ��˳���ŷŵĶ��� 
	int res=tot;
	for(int i=1;i<tot;i++){
		res+=gcd(abs(P[i+1].x-P[i].x),abs(P[i+1].y-P[i].y))-1;
	}
	res+=gcd(abs(P[1].x-P[tot].x),abs(P[1].y-P[tot].y))-1;
	return res;
}

//���ڸ������������Σ������������ʷ�+��������ķ����������
int getS(int tot,const point P[]){
	double res=0;
	for(int i=1;i<tot;i++) res+=P[i]*P[i+1];
	res+=P[tot]*p[1];
	res=fabs(res)*0.5;
	return res;
} 

//Pick��������ĳ���������Σ�����߽��ϵ�������Ϊon,���ΪS�������ڲ���������Ϊ in = ( S * 2 + 2 - on ) / 2; 

//����Բ����
struct circle{
	double x,y,r;
};
void getpoint(circle a,circle b,point &A,point &B){//��������Բ�������㣬����ΪA,B 
      double d,k;point t;
      d=dist(a,b);//Բ�ľ� 
      k=(a.r*a.r+d*d-b.r*b.r)/(2.000*d*a.r);// k cos
      k=acos(k);// k-> ����
      t.x=(b.x-a.x)/d;t.y=(b.y-a.y)/d;
      A.x=a.x+a.r*(t.x*cos(k)-t.y*(sin(k)));A.y=a.y+a.r*(t.y*cos(k)+t.x*sin(k));
      B.x=a.x+a.r*(t.x*cos(k)+t.y*(sin(k)));B.y=a.y+a.r*(t.y*cos(k)-t.x*sin(k));
} 

