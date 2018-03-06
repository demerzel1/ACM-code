/*
    ��˹��Ԫ ʱ�临�Ӷȣ�O(N^3)
    1����ʵ�������� 
    ������귢�ֺ��沿�ֻ���ϵ��ȫ��0���������0�ķ��̣����޽⣻
    ������귢�ֺ��沿����ϵ���ͽ��ȫ��0�ķ��̣���������Ԫ���������⣩ 
    2������򷽳���
    ������귢�ֺ��沿�ֻ���ϵ��ȫ��0���������0�ķ��̣����޽⣻
    ������귢�ֺ��沿��ĳ����ϵ���ͽ��ȫ��0�ķ��̣�����һ������Ԫ������⣩
    ������� num = 2^(����Ԫ����)  
*/
//1����ʵ��������
void Gauss(int N){
    int i,j,k,now=1;double t;
    for(i=1;i<=N;i++){
        for(j=now;j<=N;j++) if(fabs(A[j][i])>eps) break;
        if(j>N) continue;
        if(j!=now) for(k=1;k<=N+1;k++) swap(A[now][k],A[j][k]);
        t=A[now][i]; for(k=1;k<=N+1;k++) A[now][k]/=t;
        for(j=1;j<=N;j++){
            if(now==j) continue;
            t=A[j][i];
            for(k=1;k<=N+1;k++) A[j][k]-=t*A[now][k];
        }
        now++;
    }
    for(i=now;i<=N;i++) if(A[i][N+1]!=0) //�޽�
    if(now!=N+1) //������ 
}
//2������򷽳���(����н������)
int Gauss(int N){
	int i,j,k,now=1;
	for(i=1;i<=N;i++){
		for(j=now;j<=N;j++) if(A[j][i]) break;
		if(j>N) continue;
		if(j!=now) for(k=1;k<=N+1;k++) swap(A[now][k],A[j][k]);
		for(j=1;j<=N;j++)
		if(j!=now && A[j][i]){
			for(k=1;k<=N+1;k++) A[j][k]^=A[now][k];
		}
		++now;
	}
	for(i=now;i<=N;i++) if(A[i][N+1]) return 0; //�޽� 
	int ans=1;
	for(i=now;i<=N;i++) ans=(ans<<1) % mod;
	return ans;
}
