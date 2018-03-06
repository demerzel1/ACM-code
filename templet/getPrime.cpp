#define maxn 300
int prime[maxn];
int cnt=0;
bool valid[maxn];
void getPrime(){
    memset(valid,true,sizeof(valid));
    for(int i=2;i<=maxn;i++){
        if(valid[i]){
            cnt++;
            prime[cnt]=i;

        }
        for(int j=1;((j<=cnt)&&(i*prime[j]<=maxn));j++){
            valid[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}


#define Max 1000000
bool prime[Max];
void IsPrime(){
     prime[0]=prime[1]=0;prime[2]=1;
     for(int i=3;i<Max;i++)
        prime[i]=i%2==0?0:1;
     int t=(int)sqrt(Max*1.0);
     for(int i=3;i<=t;i++)
       if(prime[i])
         for(int j=i*i;j<Max;j+=2*i)
            prime[j]=0;
}

vector<int>v;
bool is_p(int n) {
    int m = sqrt(n) + 1;
    int nn = n;
    v.clear();
    for(int i = 2; i <= m; ++i) {
        if(n % i == 0) {
            v.push_back(i);
            while(n % i == 0) n/= i;
        }
    }
    if(n != 1) v.push_back(n);
    if((int)v.size() == 1 && v.back() == nn) return 1;
    return 0;
}
