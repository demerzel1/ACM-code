#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>


using namespace std;


struct BM
{
	static const int CHAR_SET_SIZE=256;
	static const int INPUT_STRING_SIZE=1000000+5;

	int bmBc[CHAR_SET_SIZE];
	int bmGs[INPUT_STRING_SIZE];
	int suff[INPUT_STRING_SIZE];

	char str	[INPUT_STRING_SIZE];
	char pattern[INPUT_STRING_SIZE];
	bool has_pre;

	int lstr;		//n
	int lpattern;	//m

	void PreBmBc()
	{
		for(int i=0;i<CHAR_SET_SIZE;++i)
		{
			bmBc[i]=lpattern;
		}
		for(int i=0;i<lpattern-1;++i)
		{
			bmBc[pattern[i]]=lpattern-1-i;
		}
	}
	void suffix()
	{
		int f,g,i;
		suff[lpattern-1]=lpattern;
		g=lpattern-1;
		for(i=lpattern-2;i>=0;--i)
		{
			if(i>g && suff[i+lpattern-1-f]<i-g)
				suff[i]=suff[i+lpattern-1-f];
			else
			{
				if(i<g)
					g=i;
				f=i;
				while(g>=0 && pattern[g]==pattern[g+lpattern-1-f])
					--g;
				suff[i]=f-g;
			}
		}
	}
	void PreBmGs()
	{
		int i,j;
		suffix();
		for(i=0;i<lpattern;++i)
		{
			bmGs[i]=lpattern;
		}
		j=0;
		for(i=lpattern-1;i>=0;--i)
		{
			if(suff[i]==i+1)
			{
				for(;j<lpattern-1-i;++j)
				{
					if(bmGs[j]==lpattern)
						bmGs[j]=lpattern-1-i;
				}
			}
		}
		for(i=0;i<lpattern-2;++i)
		{
			bmGs[lpattern-1-suff[i]]=lpattern-1-i;
		}
	}
	int _BM(int start)
	{
		int i,j;
		if(!has_pre)
		{
		PreBmBc();
		PreBmGs();
		has_pre=true;
		}

		j=start;
		while(j<=lstr-lpattern)
		{
			for(i=lpattern-1;i>=0 && pattern[i]==str[i+j];--i);
			if(i<0)
			{
				return j;
				//find at j
				j+=bmGs[0];
				return j;
			}
			else
			{
				j+=max(bmBc[str[i+j]]-lpattern+1+i,bmGs[i]);
			}
		}
		//cout<<"no find"<<endl;
		return -2;
	}

} bm;


int main()
{
	while(~scanf("%d",&bm.lstr))
	{
		getchar();
		gets(bm.str);
		scanf("%d",&bm.lpattern);
		getchar();
		gets(bm.pattern);
		bm.has_pre=false;
		vector<int> result;
		int r=-1;
		while(1)
		{
			r=bm._BM(r+1);
			if(r==-2)
				break;
			result.push_back(r);
		}
		printf("%d\n",result.size());
		for(int i=0;i<result.size();++i)
		{
			if(i)
				putchar(' ');
			printf("%d",result[i]+1);
		}
		putchar('\n');
	}
	return 0;
}



