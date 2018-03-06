/*
	˹̹����  ʱ�临�Ӷ�O(3 ^ K * n) HDU 4085
	���⣺����n���㣬m���ߣ�ÿ������һ��Ȩֵ����ʾ�޸���������Ҫ�Ĵ���
	��ǰk��������ȡһ��ʹ��ͺ�k�����е�ĳһ���㣬ͨ�������ӣ����ұ�����һһ��Ӧ������С�Ĵ����Ƕ���
	
	��dp[i][j]��ʾ2*K����״̬ѹ�����״̬ i�£����� j�ŵ������ֵ
	dp[i][j] = min{dp[k][j]+dp[l][j]} k,l�ϲ��ɹ���i,����k,l������j
	dp[i][j] = min{dp[i'][j']+w[j'][j]} ��j'���쵽j���ģ�ֱ��ת��
	��������ȡmin������dp[i][j]��
	
	���濼��ת�ƣ����Ƿ��ֲ�ͬ���״̬����һά�������˹�ϵ��������Ƕ��ڵڶ���ת��ͨ��spfa���������ˣ�ע��ֻ��ͬ��Ž����ٴ��ɳ�
	ÿ��һ��ʼ�ĳ�ʼֵ����ͨ����һ��ת�ƴӵ͵Ĳ�õ�
	
	����Ĵ𰸿�����һƬɭ�֣��������dp�Ժ󣬻�����һ��״ѹDP������ֻ�а���ǰK����������ͺ�K������ͬ���ǺϷ���״̬ 
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 51
#define M 2001
#define INF 1e9
using namespace std;
struct sth{
	int p,s;//p:���ڵ��λ�� s:״̬ѹ�� 
}Q[M<<1];
int n,m,K,SZ,st[N],f[1<<10],dp[1<<10][N];
int sz,to[M],v[M],pre[M],last[N];
bool mark[1<<10][N];
void Ins(int a,int b,int c){
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
bool check(int x){
	int i,num=0;
	for(i=1;i<=K;i++){
		if(x & st[i]) num++;
		if(x & st[n-K+i]) num--;
	}
	return num==0;
}
void init(){
	int i,j,a,b,c;
	memset(st,0,sizeof(st));
	memset(last,0,sizeof(last));
	scanf("%d%d%d",&n,&m,&K);
	SZ=(1<<(K*2));sz=0;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,c);Ins(b,a,c);
	}
	for(i=0;i<SZ;i++) for(j=1;j<=n;j++) dp[i][j]=INF;
	for(i=1;i<=K;i++){
		st[i]=(1<<(i-1));st[n-K+i]=(1<<(K+i-1));
		dp[st[i]][i]=0;dp[st[n-K+i]][n-K+i]=0;
	}
}
void Spfa(int t,int w){
	int i,ns,np,ts;
	while(t<=w){
		ns=Q[t].s;np=Q[t].p;
		t++;mark[ns][np]=0;
		for(i=last[np];i;i=pre[i]){
			ts=(ns|st[to[i]]);
			if(dp[ts][to[i]]>dp[ns][np]+v[i]){
				dp[ts][to[i]]=dp[ns][np]+v[i];
				if(ts==ns){
					Q[++w].s=ts;Q[w].p=to[i];mark[ts][to[i]]=1;
				}
			}
		}
	}
}
void DP(){
	int i,j,k,t,w;
	for(i=0;i<SZ;i++){
		t=1;w=0;
		for(j=1;j<=n;j++){
			if(st[j] && !(i & st[j])) continue;
			for(k=(i-1)&i;k;k=(k-1)&i) dp[i][j]=min(dp[i][j],dp[k|st[j]][j]+dp[(i^k)|st[j]][j]);
			if(dp[i][j]<INF){
				Q[++w].s=i;Q[w].p=j;mark[i][j]=1;
			}
		}
		Spfa(t,w);
	}	
	for(i=0;i<SZ;i++){
		f[i]=INF;
		if(!check(i)) continue;
		for(j=1;j<=n;j++) f[i]=min(f[i],dp[i][j]);
	}	
	for(i=1;i<SZ;i++){
		if(!check(i)) continue;
		for(k=(i-1)&i;k;k=(k-1)&i) f[i]=min(f[i],f[k]+f[i^k]);
	}
	if(f[SZ-1]>=INF) printf("No solution\n");
    else printf("%d\n",f[SZ-1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		DP();
	}
	return 0;
}

