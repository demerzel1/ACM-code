#include<stdio.h>
#include<string.h>
#include<memory.h> 
int main(){
	int i,j,T,n;
	int count[10]; 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(count,0,10*sizeof(int));
		for(i=1;i<=n;i++){
			int num=i;
			while(num>0){
				count[num%10]++;
				num/=10;
			}
		}
		for(i=0;i<9;i++)
		    printf("%d ",count[i]);
		printf("%d\n",count[9]);
	}
	return 0;
} 
