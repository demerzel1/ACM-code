#include <iostream>
#include <vector>
#include <map>

using namespace std;

using pii=pair<int,int>;

const int maxn = 100005;

int n;
int a[maxn];
map<int,vector<vector<pii> > > mp;
bool vis[maxn];
int cnt[10];
int ans;


int main () {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<pii> _;
            _.emplace_back(i,a[i]);
            vis[i]=true;
            int t=a[i];
            while(t!=i){
                vis[t]=true;
                _.emplace_back(t,a[t]);
                t=a[t];
            }
            int sz=_.size();
            mp[sz].push_back(_);
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->first==2){
            cnt[2]+=it->second.size();
        }else if(it->first==3){
            cnt[3]+=it->second.size();
        }else if(it->first==4||it->first==5){
            cnt[5]+=it->second.size();
        }else if(it->first>5){
            int t=it->first/4;
            int tt=it->first-t*4;
            cnt[5]+=it->second.size()*t;
            cnt[tt]+=it->second.size();
        }
    }
   // cout<<111<<endl;
    ans+=cnt[5];
    if(cnt[3]>=cnt[2]){
        ans+=cnt[2];
        int t=cnt[3]-cnt[2];
        int tt=t/3;
        tt*=2;
        ans+=tt;
        ans+=t-tt;
    }else{
        ans+=cnt[3];
        int t=cnt[2]-cnt[3];
        int tt=t/2;
        ans+=tt;
        ans+=t-tt*2;
    }
    cout<<ans<<endl;
    auto it=mp.end();
    it--;
    while(true){
        if(it==mp.begin()||it->first==3||it->first==2)
            break;
        if(it->first>6){
            for(auto &x:it->second){
                while(x.size()>5){
                    cout<<5<<endl;
                    for(int i=0;i<5;i++){
                        cout<<x[i].first<<' ';
                    }
                    cout<<endl;
                    for(int i=0;i<4;i++){
                        cout<<x[i].second<<' ';
                    }
                    cout<<x[0].first<<endl;
                    x[4].first=x[0].first;
                    x.erase(x.begin(),x.begin()+4);
                }
                if(x.size()<=5){
                    mp[x.size()].emplace_back(x);
                }
            }
        }else if(it->first==4||it->first==5){
            for(auto &x:it->second){
                cout<<it->first<<endl;
                for (auto &i : x)
                    cout<< i.first<<' ';
                cout<<endl;
                for (auto &i : x) {
                    cout<< i.second<<' ';
                }
                cout<<endl;
            }
        }
        it--;
    }
    if(mp[3].size()>=mp[2].size()){
        int sz=mp[2].size();
        for(int i=0;i<sz;i++){
            cout<<5<<endl;
            for(int j=0;j<3;j++)
                cout<<mp[3][i][j].first<<' ';
            for(int j=0;j<2;j++)
                cout<<mp[2][i][j].first<<' ';
            cout<<endl;
            for(int j=0;j<3;j++)
                cout<<mp[3][i][j].second<<' ';
            for(int j=0;j<2;j++)
                cout<<mp[2][i][j].second<<' ';
            cout<<endl;
        }
        mp[3].erase(mp[3].begin(),mp[3].begin()+sz);
        while(mp[3].size()>3){
            cout<<5<<endl;
            for(int i=0;i<3;i++)
                cout<<mp[3][0][i].first<<' ';
            cout<<mp[3][1][0].first<<' '<<mp[3][1][1].first<<endl;
            for(int i=0;i<3;i++)
                cout<<mp[3][0][i].second<<' ';
            cout<<mp[3][1][0].second<<' '<<mp[3][1][0].first<<endl;
            mp[3][1][1].first=mp[3][1][0].first;
            cout<<5<<endl;
            cout<<mp[3][1][1].first<<' '<<mp[3][1][2].first<<' ';
            for(int i=0;i<3;i++)
                cout<<mp[3][2][i].first<<' ';
            cout<<endl;
            cout<<mp[3][1][1].second<<' '<<mp[3][1][2].second<<' ';
            for(int i=0;i<3;i++)
                cout<<mp[3][0][i].second<<' ';
            cout<<endl;
            mp[3].erase(mp[3].begin(),mp[3].begin()+3);
        }
        for(int i=0;i<mp[3].size();i++){
            cout<<3<<endl;
            for(int j=0;j<3;j++)
                cout<<mp[3][i][j].first<<' ';
            cout<<endl;
            for(int j=0;j<3;j++)
                cout<<mp[3][i][j].second<<' ';
            cout<<endl;
        }
    }else{
        int sz=mp[3].size();
        for(int i=0;i<sz;i++){
            cout<<5<<endl;
            for(int j=0;j<3;j++)
                cout<<mp[3][i][j].first<<' ';
            for(int j=0;j<2;j++)
                cout<<mp[2][i][j].first<<' ';
            cout<<endl;
            for(int j=0;j<3;j++)
                cout<<mp[3][i][j].second<<' ';
            for(int j=0;j<2;j++)
                cout<<mp[2][i][j].second<<' ';
            cout<<endl;
        }
        mp[2].erase(mp[2].begin(),mp[2].begin()+sz);
        if(mp[2].size()%2==0){
            int sz1=mp[2].size();
            for(int i=0;i<sz1;i+=2){
                cout<<4<<endl;
                cout<<mp[2][i][0].first<<' '<<mp[2][i][1].first<<' '<<mp[2][i+1][0].first<<' '<<mp[2][i+1][1].first<<endl;
                cout<<mp[2][i][0].second<<' '<<mp[2][i][1].second<<' '<<mp[2][i+1][0].second<<' '<<mp[2][i+1][1].second<<endl;
            }
        }else{
            int sz1=mp[2].size();
            for(int i=0;i<sz1-1;i+=2){
                cout<<4<<endl;
                cout<<mp[2][i][0].first<<' '<<mp[2][i][1].first<<' '<<mp[2][i+1][0].first<<' '<<mp[2][i+1][1].first<<endl;
                cout<<mp[2][i][0].second<<' '<<mp[2][i][1].second<<' '<<mp[2][i+1][0].second<<' '<<mp[2][i+1][1].second<<endl;
            }
            cout<<2<<endl;
            cout<<mp[2][sz1-1][0].first<<' '<<mp[2][sz1-1][1].first<<endl;
            cout<<mp[2][sz1-1][0].second<<' '<<mp[2][sz1-1][1].second<<endl;
        }
    }
    return 0;
}
