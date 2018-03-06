#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,i,j,k,sum;
	cin>>a>>b>>c;
        if(a==b)
            printf("YES");
		else if(c==0){
            printf("NO");
		}
		else if(c>0){
			if(b<a)
                printf("NO");
			else if((b-a)%c==0)
                printf("YES");
			else
                printf("NO");
		}
		else{
			c=-c;
			if(b>a)
                printf("NO");
			else if((a-b)%c==0)
                printf("YES");
			else
                printf("NO");
		}

	return 0;
}
