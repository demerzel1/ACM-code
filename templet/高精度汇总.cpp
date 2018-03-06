/*
	�߾������� ���������д�� ѹ4λ 
	HPCΪ�߾���Ӣ����д����������������������� 
*/
struct HPC{
	int num[N];
};

void print(const HPC &A){// �������	
	printf("%d",A.num[A.num[0]]);
	for(int i=A.num[0]-1;i>0;i--) printf("%.4d",A.num[i]);
	printf("\n");
}

bool operator >(const HPC &a,const HPC &b){// �Ƚϴ�С 
	if(a.num[0]>b.num[0]) return 1;
	if(a.num[0]<b.num[0]) return 0;
	for(int i=a.num[0];i;i--){
		if(a.num[i]>b.num[i]) return 1;
	}
	return 0;
}

HPC operator +(const HPC &a,int b){ //�߾� + ���� 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	ans.num[1]+=b;
	for(int i=1;i<a.num[0];i++){
		ans.num[i]+=a.num[i];ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
	len=a.num[0];ans.num[len]+=a.num[len];
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

HPC operator +(const HPC &a,const HPC &b){//�߾� + �߾� 
	HPC ans;int &len=ans.num[0],L=max(a.num[0],b.num[0]);
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<L;i++){
		ans.num[i]+=a.num[i]+b.num[i];ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
	len=L;ans.num[len]+=a.num[len]+b.num[len];
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

HPC operator -(const HPC &a,const HPC &b){ //�߾� - �߾� 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<=a.num[0];i++){
		ans.num[i]+=a.num[i]-b.num[i];
		if(ans.num[i]<0) ans.num[i+1]--,ans.num[i]+=10000;
	}
	for(len=a.num[0];ans.num[len]==0;len--);
	return ans;
}

HPC operator *(const HPC &a,int b){//�߾� * ���� 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<a.num[0];i++){
		ans.num[i]+=a.num[i]*b;ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
    len=a.num[0];ans.num[len]+=a.num[len]*b;
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

HPC operator *(const HPC &a,const HPC &b){//�߾� * �߾� 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	if((a.num[0]==1 && a.num[1]==0) || (b.num[0]==1 && b.num[1]==0)){
		ans.num[0]=1;return ans;
	}
	for(int i=1;i<=a.num[0];i++)
		for(int j=1;j<=b.num[0];j++){
			ans.num[i+j-1]+=a.num[i]*b.num[j];ans.num[i+j]+=ans.num[i+j-1]/10000;ans.num[i+j-1]%=10000;
		}
	len=a.num[0]+b.num[0]-1;
	if(ans.num[len+1]>0) len++; 
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

HPC operator /(const HPC &a,int b){//�߾� / ���� 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=a.num[0];i>1;i--){
		ans.num[i-1]+=(ans.num[i]+a.num[i])%b*10000;ans.num[i]=(ans.num[i]+a.num[i])/b;
	}
	ans.num[1]=(ans.num[1]+a.num[1])/b;
	for(len=a.num[0];!ans.num[len];len--);
	return ans;
}
