string ori,pat;
int nxt[MAXN];
vector<int>node;//记录所有的匹配上的开始的点
void get_next(int m){
    int i=0,j=-1;
    nxt[0]=-1;
    while (i<m){
        if (j==-1 || pat[i]==pat[j]) nxt[++i]=++j;
        else  j=nxt[j];
    }
}
int Kmp(int n,int m){
    int i = 0,j = 0,res=0;
    node.clear();
    while (i<n){
        if(j==-1 || ori[i]==pat[j]) i++,j++;
        else j=nxt[j];

        if(j==m){
            res++;//判断出现了几次
            //node.push_back(i-j+1);记录当前匹配上的开始的点
            //return i-j; 第一次匹配上的开始的点
            j = nxt[j];
        }
    }return res;
}//先调用get_next