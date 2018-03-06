namespace Reader{
    const int L=1<<20;
    char buf[L],*s,*t;
    inline char nc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,L,stdin);
            if(s==t)return EOF;
        }
        return *s++;
    }
    template<class T>inline bool readInt(T&x){
        int c,ng=1;
        for(c=nc();~c&&c<33;c=nc());
        if(c==-1)return 0;
        if(c=='-')ng=-1,c=nc();
        for(x=0;c>32;x=(x+(x<<2)<<1)+(c^'0'),c=nc());
        x*=ng;return 1;
    }
    inline int readString(char *dest){
        int len=0;char c;
        for(c=nc();isalpha(c);dest[len++]=c,c=nc());
        dest[len]='\0';return len;
    }
}
template<typename T>inline void write(T x) {
    if(!x){putchar('0');return;}
    if (x<0) putchar('-'),x*=-1;
    char s[40]; int i=-1;
    for(;x;s[++i]=x%10+'0',x/=10);
    for(;~i;putchar(s[i--]));
}
//ios::sync_with_stdio(false); cin.tie(0);