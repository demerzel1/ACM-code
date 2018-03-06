#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  
const int maxn = 1e6 + 7;  
int id, ch[maxn][30], cnt[maxn];  
char str[15];  
void Insert(char *s)  
{  
    int rt = 0;  
    int len = strlen(s);  
    for(int i = 0; i < len; i++)  
    {  
        if(!ch[rt][s[i]-'a'])  
        {  
            memset(ch[id], 0, sizeof(ch[id]));  
            cnt[id] = 0;  
            ch[rt][s[i]-'a'] = id++;  
        }  
        rt = ch[rt][s[i]-'a'];  
        cnt[rt]++;  
    }  
}  
int match(char *s)  
{  
    int rt = 0;  
    int len = strlen(s);  
    for(int i = 0; i < len; i++)  
    {  
        if(!ch[rt][s[i]-'a'])  
            return 0;  
        rt = ch[rt][s[i]-'a'];  
    }  
    return cnt[rt];  
}  
int main()  
{  
    id = 1;  
    memset(ch[0], 0, sizeof(ch[0]));  
    while(gets(str))  
    {  
        if(!strlen(str)) break;  
        Insert(str);  
    }  
    while(gets(str) != NULL)  
        printf("%d\n", match(str));  
    return 0;  
}  