#include<stdio.h>
#include<string.h>
int main(){
	int T;
	char str[100];
	scanf("%d",&T);
	while(T--){
		memset(str,0,sizeof(str));
		scanf("%s",str);
		int i,j,flag=0,l=strlen(str);
		for(i=1;flag==0||i<l;i++){
			for(j=0;j<i||(j+i)<l;j++){
				if(str[j]!=str[j+i])   break; 
			}
			if(j==i)    flag=1;
		}
		if(flag==1)
		    printf("%d\n",j);
		else
		    printf("%d\n",l);
	}
	return 0;
}
