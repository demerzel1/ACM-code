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

    int e;//��¼e��λ��;

    a=s[0]-'0';//a;
    for(int i=2; i<l; i++)
    {
        if(s[i]=='e')
        {
            e=i;
            break;
        }
        if(s[i]=='0')
            zero_d++;//0�ĸ���;
        else
            dd++;//����0�ĸ���;
    }
    int f=1;
    for(int i=l-1; i>e; i--)
    {
        b+=(s[i]-'0')*f;//b
        f*=10;
    }

    if(a==0&&b==0)//a,b����0�����;
    {
        if(zero_d==e-2)//d��ȫ��0;
            printf("0");
        else
            for(int i=0; i<e; i++)
                printf("%c",s[i]);
    }
    else if(b==0&&a!=0)//b��0,a����0;
    {
        if(zero_d==e-2)//d ȫ��0;
            printf("%d",a);
        else
        {
            for(int i=0; i<e; i++)
                printf("%c",s[i]);
        }
    }
    else if(a!=0&&b!=0)//ͬʱ��Ϊ0;
    {
        if(e-2<b)//b����d�ĳ���;
        {
            b-=e-2;//b������Ǵ�ʱd�ĳ���;
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
            if(e-2!=b)//d�ĳ��Ȳ�����bҪ������Ƶĳ���;
            {
                printf(".");
                for(int i=b+2; i<e; i++)
                    printf("%c",s[i]);
            }
        }
    }
    return 0;
}
