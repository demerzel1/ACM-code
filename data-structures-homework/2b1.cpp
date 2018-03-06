#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
#define Maxn 10005
typedef struct tagStudent
{
    char name[35];
    int score;
    int index;
}Student;

Student stu[Maxn],Temp[Maxn];
int n,m;
int cmpName(const void *a,const void *b)
{
    return strcmp(((Student *)a)->name,((Student *)b)->name);
}
int f(char str[])
{
	int l=0,r=n-1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(!strcmp(str,stu[mid].name))
			return mid;
		else if(strcmp(str,stu[mid].name)>0)
			l=mid+1;
		else
			r=mid-1;
	}
	return l;
}
int main()
{
	int i,pos;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
		gets(stu[i].name);
	qsort(stu,n,sizeof(stu[0]),cmpName);
	for(i=0;i<n;i++)
		if(!strcmp(stu[i].name,"Li Ming"))
		{
			pos=i;
			break;
		}
	scanf("%d",&m);
	while(m--)
	{
		int ans=1;
		char tag[35];
		int temp;
		for(i=0;i<n;i++)
		{
			scanf("%d ",&temp);
			gets(tag);
			stu[f(tag)].score+=temp;
		}
		for(i=0;i<n;i++)
			if(stu[pos].score<stu[i].score)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
