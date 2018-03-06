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