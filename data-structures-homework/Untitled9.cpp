#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    char s[200];
    memset(s,0,sizeof(0));
    scanf("%s",s);
    int zero_d=0,dd=0;
    int l=strlen(s), a , num[109] , b=0;

    int e;//记录e的位置;

    a=s[0]-'0';//a;
    for(int i=2; i<l; i++)
    {
        if(s[i]=='e')
        {
            e=i;
            break;
        }
        if(s[i]=='0')
            zero_d++;//0的个数;
        else
            dd++;//不是0的个数;
    }
    int f=1;
    for(int i=l-1; i>e; i--)
    {
        b+=(s[i]-'0')*f;//b
        f*=10;
    }

    if(a==0&&b==0)//a,b都是0的情况;
    {
        if(zero_d==e-2)//d中全是0;
            printf("0");
        else
            for(int i=0; i<e; i++)
                printf("%c",s[i]);
    }
    else if(b==0&&a!=0)//b是0,a不是0;
    {
        if(zero_d==e-2)//d 全是0;
            printf("%d",a);
        else
        {
            for(int i=0; i<e; i++)
                printf("%c",s[i]);
        }
    }
    else if(a!=0&&b!=0)//同时不为0;
    {
        if(e-2<b)//b超过d的长度;
        {
            b-=e-2;//b代表的是此时d的长度;
            printf("%d",a);
            for(int i=2; i<e; i++)
                printf("%c",s[i]);
            for(int i=1; i<=b; i++)
                printf("0");
        }
        else
        {
            printf("%d",a);
            for(int i=2; i<=b+1; i++)
                printf("%c",s[i]);
            if(e-2!=b)//d的长度不等于b要求向后推的长度;
            {
                printf(".");
                for(int i=b+2; i<e; i++)
                    printf("%c",s[i]);
            }
        }
    }
    return 0;
}
