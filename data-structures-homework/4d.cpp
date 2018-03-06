#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
char square[60][60];
int n;
int count;
void solve(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
            int flag=1;
			if(square[i][j]=='#'){
				int cl=0,cr=0,cu=0,cd=0;
				int x=i,y=j;
				while(y>=1){
					y--;
					if(square[x][y]=='#'){
                        cl++;
                        if(square[x-1][y]=='#'||square[])
					}

                    }
				}
				x=i;
				y=j;
				while(y<=n){
					y++;
					if(square[x][y]=='#')
						cr++;
				}
				x=i;
				y=j;
				while(x>=1){
					x--;
					if(square[x][y]=='#')
						cu++;
				}
				x=i;
				y=j;
				while(x<=n){
					x++;
					if(square[x][y]=='#')
						cd++;
				}
				printf("%d %d %d %d\n",cl,cr,cu,cd);
				if(cl==cr&&cl==cu&&cl==cd&&flag){
                    int x=i,y=j;

					count++;
				}
			}
		}
		printf("%d\n",count);
}
int main(){
	while(scanf("%d",&n)){
        if(n==0){
            cout<<"break"<<endl;
            break;
        }

		count=0;
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
               cin>>square[i][j];
          //      cout<<i<<" "<<j<<endl;
			}

		for(i=0;i<=n+1;i++){
			square[i][0]='o';
			square[i][n+1]='o';
		}
		for(j=0;j<=n+1;j++){
			square[0][j]='o';
			square[n+1][j]='o';
		}

		solve();
	}
	return 0;
}
