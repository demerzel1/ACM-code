#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define inf 1<<30
#define maxn 10005
#define LOOP(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
string ch;
void clear_first_zero()
{
	string::iterator it = ch.begin();
	if (*it == '.'){
		ch.insert(it, '0');
		return;
	}
	int t=0;
	for (int i = 0; i < ch.size(); i++)
	{
		if (ch[i] == '0'&&ch[i+1]!='.')
			t++;
		else
			break;
	}
	ch = ch.erase(0, t);
	if (!ch.size())
		ch = "0";
}
void clear_last_zero()
{
	int pos = ch.find('.', 0);
	if (pos == -1)
	{
		//ch += '.';
		return;
	}
	int t = ch.size();
	for (int i = ch.size() - 1; i >= 0; i--)
	{
		if (ch[i] == '0') t--;
		else if (ch[i] == '.') { t--; break; }
		else break;
	}
	ch = ch.erase(t, ch.size());
}
int move()
{
	int pos = ch.find('.', 0), change = 0;
	if (ch.size() == 1) return 0;
	if (pos == -1  ) {
		ch += '.';
		pos = ch.find('.', 0);
	}
	if (pos >= 2)
	{
		for (int i = pos; i >= 2; i--)
		{
			swap(ch[i], ch[i - 1]);
			//Right = sum(Right, add);
			change++;
		}
		//clear_first_zero();
		clear_last_zero();
	}
	else
	{

		string::iterator it = ch.begin();
		if (*it != '0'&&*(it+1)=='.'&&(it+2)!=ch.end()||ch=="0") return 0;
		for (int i = 0; i < ch.size(); i++)
		{
			if (ch[i] != '0'&& ch[i] != '.')
				break;
			if (ch[i] != '.') change--;
		}
		ch=ch.erase(0, -change+1);
		if(ch.size()>1)
			ch.insert(ch.begin() + 1, '.');
	}
	return change;
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	cin >> ch;
	clear_first_zero();
	clear_last_zero();
	int t = move();
	if (t > 0)
		cout << ch << "E" << t << endl;
	else if (t < 0)
	else
		cout << ch << endl;
}
