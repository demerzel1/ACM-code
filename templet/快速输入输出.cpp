int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0' && ch<='9')){ch=getchar();if(ch=='-') f=-1;}
	while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
long long read(){
	long long x=0,f=1;char ch=getchar();
	while(!(ch>='0' && ch<='9')){ch=getchar();if(ch=='-') f=-1;}
	while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
void print(int x,char ZF)//�������x,������Ը�һ���ַ�����ո񡢻��е� 
{
    if(x==0){
		putchar('0');putchar(ZF);return;
	}
    int num=0;char ch[10];
    while(x>0) ch[++num]=(x%10+'0'),x/=10;
    while(num>0) putchar(ch[num--]);
    putchar(ZF);
}
