#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,m;
int square[3][maxn];
int pre[3][maxn];
int ans[maxn];
int k,l,r;

int main() {
    memset(ans,1000000,sizeof(ans));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d",&square[i%2][j]);
            if(i==1) {
                pre[i%2][j]=1;
            } else if(i>1) {
                if(square[i%2][j]>=square[(i-1)%2][j]) {
                    pre[i%2][j]=pre[(i-1)%2][j];
                } else {
                    pre[i%2][j]=i;
                }
            }
            if(j>1){
                ans[i]=min(ans[i],pre[i%2][j]);
                printf("pre=%d %d ",pre[i%2][j],ans[i]);
            }
        }
        printf("%d ",ans[i]);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&l,&r);
        if(ans[r]<=l)
            printf("Yes");
        else
            printf("No");
        printf("\n");
    }
    return 0;
}


/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> x;
int s[100010];
int c[100010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	int temp;
	int Min;
	fill(c,c+100002,1);
	for(i=1;i<=n;i++)
	{
		Min=1000000010;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&temp);
			if(temp>=s[j])
			{
			}
			else
			{
				c[j]=i;
			}
			if(Min>c[j])
			 Min=c[j];
			s[j]=temp;
		}
		x.push_back(Min);
	//	cout<<Min<<endl;
	}
	int y;
	scanf("%d",&y);
	int f,g;
	for(i=0;i<y;i++)
	{
		scanf("%d%d",&f,&g);
		if(x[g-1]<=f)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
*/
