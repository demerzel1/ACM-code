bool np[MAXN];//prime==0
vector<int>prime;
//int phi[MAXN];//欧拉函数
//int sum[MAXN+10];//n的质因数的和
void getprime(){//筛法
    int tot=-1;//phi[1]=1;
    for (int i=2; i<MAXN; i++) {
        if (!np[i]) {
            ++tot;
            prime.emplace_back(i);
            //phi[i]=i-1;
            //sum[i]=i;
        }
        for (int j=0; (j<=tot)&&(i*prime[j]<=MAXN);j++) {
            np[i*prime[j]]=1;
            if (i%prime[j] == 0) {
                //phi[i*prime[j]]=phi[i]*prime[j];
                //sum[i*prime[j]]=sum[i];
                break;
            }
            /*else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            	sum[i*prime[j]]=sum[i]+prime[j];
            }*/
        }
    }
}