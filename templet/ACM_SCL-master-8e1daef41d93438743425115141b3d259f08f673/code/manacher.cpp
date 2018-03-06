struct Manacher{
    char a[MAXN<<1];
    int p[MAXN<<1],l;
    void get(char *o){
        l=strlen(o);
        for(int i=0;i<l;i++){
            a[i<<1]='#';
            a[i<<1|1]=o[i];
        }
        l<<=1,l++; a[l-1]='#';

        int mx=0,id=0;
        for(int i=0;i<l;i++){
            p[i]=mx>i?min(p[(id<<1)-i],mx-i):1;
            while(i-p[i]>=0 && i+p[i]<l && a[i+p[i]]==a[i-p[i]])p[i]++;
            if(i+p[i]>mx) mx=i+p[i],id=i;
        }
    }
};