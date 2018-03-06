#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;
map<int,string> mp1;
void init() {
    mp["1m"]=1,mp["2m"]=2,mp["3m"]=3,mp["4m"]=4,mp["5m"]=5;
    mp["6m"]=6,mp["7m"]=7,mp["8m"]=8,mp["9m"]=9;
    mp["1s"]=10,mp["2s"]=11,mp["3s"]=12,mp["4s"]=13,mp["5s"]=14;
    mp["6s"]=15,mp["7s"]=16,mp["8s"]=17,mp["9s"]=18;
    mp["1p"]=19,mp["2p"]=20,mp["3p"]=21,mp["4p"]=22,mp["5p"]=23;
    mp["6p"]=24,mp["7p"]=25,mp["8p"]=26,mp["9p"]=27;
    mp["1c"]=28,mp["2c"]=29,mp["3c"]=30,mp["4c"]=31,mp["5c"]=32;
    mp["6c"]=33,mp["7c"]=34;
    for(auto it=mp.begin(); it!=mp.end(); it++) {
        mp1[it->second]=it->first;
    }
}

int shisanyao[20]= {1,9,19,27,10,18,28,29,30,31,32,33,34};

int cnt[40];
int tc[40];
int a[20];
int ans=0;
vector<int> tiles;

bool judge1();

bool judge(int x) {
    memset(tc,0,sizeof(tc));
    tc[x]++;
    int cnt_pair=0;
    for(int i=1; i<=34; i++) {
        tc[i]+=cnt[i];
        if(tc[i]>4)
            return false;
        if(tc[i]==2)
            cnt_pair++;
    }
    if(cnt_pair==7) {
        return true;
    }
    if(cnt_pair==1) {
        bool flag=true;
        int tcnt=0;
        for(int j=0; j<13; j++) {
            if(tc[shisanyao[j]]==1)
                continue;
            if(tc[shisanyao[j]]>2||tc[shisanyao[j]]==0) {
                flag=false;
                break;
            }
            if(tc[shisanyao[j]]==2) {
                tcnt++;
            }
        }
        //  cout<<tcnt<<" tcnt\n";
        if(tcnt==1&&flag) {
            return true;
        }
    }
    for(int i=1; i<=34; i++) {
        if(tc[i]>=2) {
            tc[i]-=2;
            if(judge1())
                return true;
            tc[i]+=2;
        }
    }
    return false;
}

bool judge1() {
    int ttc[40];
    for(int i=1; i<=34; i++) {
        ttc[i]=tc[i];
    }
    int tcnt=0;
    for(int i=1; i<=34; i++) {
        if(ttc[i]>=3) {
            tcnt++;
            ttc[i]-=3;
        }
        while(true) {
            if(ttc[i]>0&&i<=25&&i!=8&&i!=9&&i!=17&&i!=18) {
                if(ttc[i+1]>0&&ttc[i+2]>0) {
                    ttc[i]--;
                    ttc[i+1]--;
                    ttc[i+2]--;
                    tcnt++;
                }else
                    break;
            }else
                break;
        }
    }
    if(tcnt==4)
        return true;
    return false;
}

int main() {
    init();
    int T;
    cin>>T;
    while(T--) {
        ans=0;
        tiles.clear();
        memset(cnt,0,sizeof(cnt));
        memset(a,0,sizeof(a));
        string s;
        for(int i=0; i<13; i++) {
            cin>>s;
            cnt[mp[s]]++;
        }
        for(int i=1; i<=34; i++) {
            if(judge(i)) {
                ans++;
                tiles.push_back(i);
            }
        }
        if(ans==0) {
            cout<<"Nooten\n";
            continue;
        }
        cout<<ans;
        for(int i=0; i<tiles.size(); i++) {
            cout<<" "<<mp1[tiles[i]];
        }
        cout<<"\n";
    }
    return 0;
}
