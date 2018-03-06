/*
	����Hash ��������Hashʱ�ĳ�ͻ HDU 1004
	����һ�ѵ��ʣ�ѯ���ĸ����ʳ��ִ������ 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1001
#define M 300000
using namespace std;
int n,sz,sum,num[N],pre[N],last[M];
string s,word[N],ans;
void Hash(string p){
	int i,j,k=0,len=p.size();
	for(i=0;i<len;i++) k=(k*26+(p[i]-'a'))%M;
	for(j=last[k];j;j=pre[j]){
		if(word[j]==p){
			num[j]++;return;
		}
	}
	sz++;word[sz]=p;num[sz]=1;pre[sz]=last[k];last[k]=sz;
}
int main(){
	while(scanf("%d",&n) && n){
		memset(last,0,sizeof(last));
		sz=1;sum=0;
		for(int i=1;i<=n;i++){
			cin>>s;Hash(s);
		}
		for(int i=1;i<=sz;i++){
			if(num[i]>sum){
				sum=num[i];ans=word[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

