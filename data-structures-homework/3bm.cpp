/*
Sk的长度：
k的范围
[1  , 9  ]: k
[10 , 99 ]: 9 + (k-9)*2
[100, 999]: 9 + 90*2 + (k-99)*3
...
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAXN 31270
#define MAXLEN 146000

unsigned int seqLen[MAXN];

void InitSequenceLength(void)
{
	seqLen[0] = 0;
	unsigned int delta = 1, c = 10, sum = 0;

	int i;
	for (i = 1; seqLen[i-1] <= 2147483647; i++)
	{
		//当i为10、100、1000...时，delta需要加1
		if (i == c)
		{
			delta++;
			c *= 10;
		}
		sum += delta;
		seqLen[i] = seqLen[i-1] + sum;
//		cout<<seqLen[i]<<endl;
	}
}

int BSearch(int low, int high, unsigned int targ)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (targ == seqLen[mid])
		{
			return seqLen[mid-1];
		}
		else if (targ < seqLen[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout<<seqLen[high]<<endl;
	return seqLen[high];
}

int main(void)
{
	InitSequenceLength();
	string maxSeq;
	maxSeq.reserve(MAXLEN+10);
	int i;
	for (i = 1; maxSeq.length() < MAXLEN; i++)
	{
		char temp[10];
		sprintf(temp, "%d", i);
		maxSeq += temp;
	}

	int ncases;
	scanf("%d", &ncases);

	while (ncases--)
	{
		unsigned int p;
		scanf("%d", &p);
		int i = BSearch(1, 31268, p);
		printf("%c\n", maxSeq[p-i-1]);
	}
	return 0;
}
