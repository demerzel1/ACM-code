#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
typedef struct Text
{
	int num;
	int pre;
}Text;

struct cmp{
	bool operator () (const Text a,const Text b)
	{
		if(a.num!=b.num)
		  return a.num>b.num;
		else
		  return a.pre>b.pre;
	}
};
int Is(char n)
{
	int a;
	switch(n)
	{
		case 'A':
			a=14;
			break;
		case 'T':
			a=10;
			break;
		case 'J':
			a=11;
			break;
		case 'Q':
			a=12;
			break;
		case 'K':
			a=13;
			break;
		default:
			a=n-'0';
			break;
	}
	return a;
}
int No(char n)
{
	int a;
	switch(n)
	{
		case 'H':
			a=4;
			break;
		case 'S':
		    a=3;
		    break;
		case 'D':
			a=2;
			break;
		case 'C':
			a=1;
			break;
	}
	return a;
}
bool comp(Text a,Text b)
{
	if(a.num==b.num)
	{
		if(a.pre<=b.pre)
		 return true;
	}
	else
	{
		if(a.num<b.num)
		  return true;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	priority_queue<Text,vector<Text>,cmp> x;  //ÑÇµ±
	priority_queue<Text,vector<Text>,cmp> y;  //ÏÄÍÞ
	int m;
	while(n--)
	{
		scanf("%d\n",&m);
		int i=0;
		char temp;
		Text t;
		for(;i<m;i++)
		{
			temp=getchar();
			t.num=Is(temp);
			temp=getchar();
			t.pre=No(temp);
			x.push(t);
		//	cout<<"t="<<x.top().num<<ends<<x.top().pre<<endl;
			getchar();
		}
		for(i=0;i<m;i++)
		{
			temp=getchar();
			t.num=Is(temp);
			temp=getchar();
			t.pre=No(temp);
			y.push(t);
		//	cout<<"t="<<t.num<<ends<<t.pre<<endl;
			getchar();
		}
		Text t1;
		int count=0;
		int left=m; //ÏÄÍÞÊ£ÓàµÄÅÆÊý
		int flag;
		t1=x.top();
		while(!y.empty()&&!x.empty())
		{
			flag=1;
		//	cout<<"hbdjsb"<<endl;
			t=y.top();
		//	cout<<"t="<<t.num<<ends<<t.pre<<endl;
			y.pop();
		//	if(x.)
		//	x.push(t);

			while(!x.empty()&&left&&comp(t1,t))
			{
			//	cout<<"$$$$$$"<<endl;
				count++;
				x.pop();
				left--;
				if(!x.empty())
				t1=x.top();
				flag=0;
			}
			if(flag)
			  left--;

		}

		cout<<count<<endl;
		while(!y.empty())
             y.pop();
        while(!x.empty())
             x.pop();
	}
	return 0;
}
