#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	char puzzle[5][5];
	int i,j,count=1;
	while(gets(puzzle[0])){
		int flag=0;
		if(puzzle[0][0]=='Z')
			break;
		for(i=1;i<5;i++)
			gets(puzzle[i]);
		if(count>1)
			cout<<endl;
//			for(i=0;i<5;i++)
//					for(j=0;j<4;j++){
//						cout<<puzzle[i][j]<<" ";
//						if(j==3){
//							cout<<puzzle[i][j+1]<<endl;
//				}	
//			}
			
			
		printf("Puzzle #%d:\n",count);
		char op;
		while(cin>>op){
			if(op=='0'){
				break;
			}
				
			int x,y;
			int i,j;
			for(i=0;i<5;i++)
				for(j=0;j<5;j++){
					if(puzzle[i][j]==' '){
						x=i;
						y=j;
					}
				}
//		printf("%d %d\n",x,y); 
			switch(op){
				case 'A':
					if(x==0){
						flag=1;
						break;
					}
					else{
						char t;
						t=puzzle[x-1][y];
						puzzle[x-1][y]=' ';
						puzzle[x][y]=t;
						break;
					}
				case 'B':
					if(x==4){
						flag=1;
						break;
					}
					else{
						char t;
						t=puzzle[x+1][y];
						puzzle[x+1][y]=' ';
						puzzle[x][y]=t;
						break;
					}
				case 'L':
					if(y==0){
						flag=1;
						break;
					}
					else{
						char t;
						t=puzzle[x][y-1];
						puzzle[x][y-1]=' ';
						puzzle[x][y]=t;
						break;
					}
				case 'R':
					if(y==4){
						flag=1;
						break;
					}
					else{
						char t;
						t=puzzle[x][y+1];
						puzzle[x][y+1]=' ';
						puzzle[x][y]=t;
						break;
					}
//					if(flag){
//						cout<<"This puzzle has no final configuration."<<endl;
//						break; 
//					}
			}
			if(flag){
				cout<<"This puzzle has no final configuration."<<endl;
				getchar();
				break;
			}
//				break;
		}
		if(flag);
			else{
				for(i=0;i<5;i++)
					for(j=0;j<4;j++){
						cout<<puzzle[i][j]<<" ";
						if(j==3){
							cout<<puzzle[i][j+1]<<endl;
				}	
			}
			}
	getchar();
	count++;
	}
	return 0;
}
