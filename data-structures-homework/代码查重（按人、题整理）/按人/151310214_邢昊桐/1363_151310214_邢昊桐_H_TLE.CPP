#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <hash_map>
#define MAXN 1000005
using namespace std;
int len_str;
int len_key;
string str;
string key;
int cnt;
vector<int> vec;
int NEXT[MAXN];

void makenext()
{
    int i=0;
    int j=-1;
    NEXT[0]=-1;
    while(i<len_str)
    {
        if(j==-1 || str[i]==str[j])
        {
            i++;
            j++;
            NEXT[i]=j;
        }
        else j=NEXT[j];
    }
}

void KMP()
{
    int i=0,j=0;
    while(i<len_str&&j<len_key)
    {
        if(str[i]==key[j]||j==-1) i++,j++;
        else j=NEXT[j];
        if(j==len_key)
        {
            j=0;
            vec.push_back(i-len_key+1);
            i=i-len_key+1;
            cnt++;
        }
    }
}

int main()
{
    while(cin>>len_str)
    {
        getchar();
        getline(cin,str);
        cin>>len_key;
        getchar();
        getline(cin,key);
        vec.clear();
        cnt=0;
        memset(NEXT,0,sizeof(NEXT));
        makenext();
        KMP();
        cout<<cnt<<endl;
        if(cnt)
        {
            for(int i=0; i<cnt-1; i++)
            {
                cout<<vec[i]<<" ";
            }
            cout<<vec[cnt-1]<<endl;
        }

    }
    return 0;
}

