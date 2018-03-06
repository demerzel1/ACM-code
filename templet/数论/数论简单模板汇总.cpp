//���۶��ģ��Ļ���
//0��������
int quickpow(int a,int b,int p){// a ^ b % p
	int res=1;
	while(b>0){
		if(b & 1) res=(res*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return res;
}

//1����ɸ���� ɸ��1-N������ 
int prime[N],tot;
bool mark[N];
void getphi(){  
   for(int i=2;i<=N;i++){
       if(!mark[i])  prime[++tot]=i;
       for(int j=1;j<=tot;j++){
          if(i*prime[j]>N)  break;
          mark[i*prime[j]]=1;
          if(i%prime[j]==0) break;
       }
   }
}
//2����ɸ��Ԫ ����������������£�ɸ��1~p-1����p����Ԫ 
for(i=2;i<p;i++) Inv[i]=(Inv[p%i]*(p-p/i))%p;

//3�����ŷ������ 
//(1)���Ӷ� sqrt(n)
int getphi(int x){
	phi=1;
	for(i=2;i*i<=x;i++){
		if(x%i==0){
			x/=i;phi*=i-1;
			while(x%i==0){
				x/=i;phi*=i;
			}
		}
	}
	if(x>1)	phi*=x-1;
	return phi;
}		
//(2)��ɸ1~N��ŷ������
int phi[],prime[],tot;
bool mark[]; 
void getphi(){
	phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!check[i])  {tot++;prime[tot]=i;phi[i]=i-1;}
		for(int j=1;j<=tot;j++){
			if(i*prime[j]>1000)  break;
			check[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i * prime[j]]=phi[i]*prime[j];break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
} 
/*4����ɸĪ����˹���� 
����һ������uֵ�������£�
	1���������ĳ��ƽ�������ϵ������� : 0
	2�����������������ͬ�������� ��-1
	2���������ż������ͬ�������� ��1
*/
int tot,prime[],u[]; 
bool mark[]; 
void getu(){  
    u[1]=1; 
    for(int i=2;i<=N;i++) { 
        if(!mark[i])  {prime[++tot]=i;u[i]=1;} 
        for(int j=1;j<=tot;j++) { 
            if(i*prime[j]>N)  break; 
            mark[i*prime[j]]=1; 
            if(i%prime[j]==0){
				u[i*prime[j]]=0;break;
			} 
            else u[i*prime[j]]=u[i]*(-1); 
        } 
    } 
}  
//5����չŷ������㷨 ax+by=gcd(a,b)
long long x,y;
int exgcd(int a,int b){
    if(b==0){
        x=1;y=0;
		return a;
    }
    int d=exgcd(b,a%b),t=x;
    x=y;
    y=t-a/b*y;
    return d;
} 
//6�����ݴ󷨣�
//A ^ phi(P) = 1 (mod P) (A,P����)  
//����ʽ�ɵã���PΪ����ʱ��phi(P)=P-1  ���A ^ (P-2) * A = 1 (mod P),��A ^ (P-2)ΪA����P����Ԫ 
//���ھ��󣬵�A����ʱ�����ݴ���Ȼ����

//7������ɭ����
//S = (f(l) + f(r) + 4 * f(mid)) * (r - l) / 6 
//Ϊ��֤���ȣ���Ҫ����Ӧ��ʽ��f(x)Ϊ���㺯����xλ�õ�yֵҲ����˵�Ǹ��ǵĳ��ȣ�������� 
double calc(double len,double fl,double fmid,double fr){
    return (fl+fr+4*fmid)*len/6;
}
double simpson(double l,double mid,double r,double fl,double fmid,double fr,double s){
    double m1=(l+mid)*0.5,m2=(mid+r)*0.5;
    double fm1=f(m1),fm2=f(m2);
    double s1=calc(mid-l,fl,fm1,fmid),s2=calc(r-mid,fmid,fm2,fr);
    if(fabs(s-s1-s2)<eps)  return s1+s2;
    return simpson(l,m1,mid,fl,fm1,fmid,s1)+simpson(mid,m2,r,fmid,fm2,fr,s2);
}

/*8������������
//f[0]=1,f[1]=1
//���ƹ�ʽ:f[n]=f[0]*f[n-1]+f[1]*f[n-2]+...f[n-1]*f[0](n>=2) 
//�����:f[n]=C(2n,n)-C(2n,n-1)��f[n]=C(2n,n)/(n+1)
//Ӧ�ã���ջ����͹��������ǻ��֡�n���ڵ�Ķ������� 
*/



