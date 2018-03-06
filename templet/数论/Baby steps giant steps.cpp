/*
	BSGS�㷨�����y ^ x = z (mod p)����С�Ǹ�������
	ʱ�临�Ӷȣ�sqrt(p) 
	N ����Χ��С�Ǹ���(p) M ��Hash��ķ�Χ
	quickpow()Ϊ������ 
*/
int sz,num[N],pre[N],last[M];
int quickpow(int a,int b,int p){
	int res=1;a%=p;
	while(b>0){
		if(b & 1) res=(long long)res*a%p;
		b>>=1;
		a=(long long)a*a%p;
	}
	return res;
}
void Hash(int x,int y){
	sz++;num[sz]=y;pre[sz]=last[x];last[x]=sz;
}
int BSGS(int y,int z,int p){ //return -1��ʾ�޽�   
	memset(last,0,sizeof(last));
	sz=0;z%=p;
	if(z==1) return 0;
	if(y%p==0){
		if(z==0) return 1;
		else return -1;
	}
	int i,j,mi,limt=sqrt(p),now=z;
	for(i=1;i<=limt+1;i++){
		Hash(now%M,now);
		now=(long long)now*y%p;
	}
	now=1;mi=quickpow(y,limt,p);
	for(i=1;i<=limt+1;i++){
		now=(long long)now*mi%p;
		for(j=last[now%M];j;j=pre[j]){
			if(num[j]==now){
				return i*limt-j+1;
			}
		}
	}
	return -1;
}
